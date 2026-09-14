#!/usr/bin/env python3
"""Problem of the day mailer.

Sends an 800-1000 rated Codeforces problem each morning, with escalating
reminders on a strict 6-hour clock. Times are Indiana local.

Slots (America/Indiana/Indianapolis):
    08:00  new problem   (+ red alert banner if yesterday's is unsolved)
    14:00  follow-up / red alert
    20:00  follow-up / red alert
    02:00  follow-up / red alert

Red alerts only ever concern *yesterday's* problem. Once a problem is two
days old it is dropped and never mentioned again.

Follow-ups require CF_HANDLE to be set -- without a handle there is no way
to tell whether anything was solved, so only the 08:00 mail goes out.
"""
import argparse, datetime, html, json, os, random, smtplib, ssl, sys, urllib.request
from email.message import EmailMessage
from zoneinfo import ZoneInfo

TZ = ZoneInfo("America/Indiana/Indianapolis")
SLOTS = {8: "new", 14: "followup", 20: "followup", 2: "followup"}
NEW_SLOT = 8            # the slot that carries the problem itself
FOLLOWUP_GRACE = 3      # hours a reminder may run late before it is just noise
RATING_LO, RATING_HI = 800, 1000
MIN_SOLVERS = 400
AGE_TIERS = [2023, 2020, 0]          # newest first; widen only when exhausted
HOLDBACK = ("Div3", "Div4", "Educational")   # newest of each reserved for virtuals
UA = {"User-Agent": "cp-potd/1.0 (personal practice reminder)"}
STATE = os.path.join(os.path.dirname(os.path.abspath(__file__)), "state.json")

# --------------------------------------------------------------------------
# Message bodies. Edit these freely -- no logic depends on their contents.
# --------------------------------------------------------------------------

MSG_NEW = (
    "Here is your problem of the day! This is your highest priority item to "
    "complete today. If you have to choose between this and saying goodbye to "
    "your loved ones in case of an apocalyptic-level cataclysm, you should be "
    "aiming for an AC. Reminders will be sent in case of failure to adhere to "
    "these instructions. AI submissions will not be tolerated. Happy coding!"
)

MSG_FOLLOWUP = (
    "Our systems indicate that you have not submitted your problem today! In "
    "order to maintain your position as the favorite child in this family, "
    "please practice and get good at competitive programming. We will be "
    "expecting a submission shortly."
)

RED_ALERT_BODY = (
    "RED ALERT. NO SUBMISSIONS DETECTED FOR PAST PROBLEMS. YOUR STATUS AS "
    "FAVORITE CHILD HAS BEEN SUSPENDED PENDING REVIEW. THIS IS NOT A DRILL."
)


def get(url):
    with urllib.request.urlopen(urllib.request.Request(url, headers=UA), timeout=45) as r:
        return json.load(r)


# ---------------- state ----------------

def load_state():
    try:
        with open(STATE) as f:
            return json.load(f)
    except (OSError, ValueError):
        return {"assigned": {}, "sent_keys": [], "sent_slots": {}, "lc_sent_slugs": [], "tier": 0}


def save_state(s):
    with open(STATE, "w") as f:
        json.dump(s, f, indent=2, sort_keys=True)
        f.write("\n")


# ---------------- codeforces ----------------

def category(name):
    if "Div. 3" in name:
        return "Div3"
    if "Div. 4" in name:
        return "Div4"
    if name.startswith("Educational"):
        return "Educational"
    return None


def held_back_contests(contests):
    """Newest finished contest in each reserved category -- kept free for virtuals."""
    newest = {}
    for c in sorted(contests, key=lambda c: -c["startTimeSeconds"]):
        k = category(c["name"])
        if k in HOLDBACK and k not in newest:
            newest[k] = c["id"]
    return set(newest.values()), newest


def solved_set(handle):
    if not handle:
        return set()
    try:
        d = get(f"https://codeforces.com/api/user.status?handle={handle}&from=1&count=10000")
    except Exception as e:
        print(f"[warn] could not fetch submissions for {handle}: {e}", file=sys.stderr)
        return set()
    if d.get("status") != "OK":
        return set()
    return {f"{s['problem']['contestId']}-{s['problem']['index']}"
            for s in d["result"]
            if s.get("verdict") == "OK" and "contestId" in s.get("problem", {})}


def pick_problem(state, handle):
    cl = get("https://codeforces.com/api/contest.list")
    contests = [c for c in cl["result"]
                if c.get("phase") == "FINISHED" and "startTimeSeconds" in c]
    hold, hold_names = held_back_contests(contests)
    year = {c["id"]: datetime.datetime.fromtimestamp(c["startTimeSeconds"], TZ).year
            for c in contests}

    ps = get("https://codeforces.com/api/problemset.problems")
    stats = {f"{s['contestId']}-{s['index']}": s["solvedCount"]
             for s in ps["result"]["problemStatistics"] if "contestId" in s}

    already = set(state["sent_keys"]) | solved_set(handle)

    base = []
    for p in ps["result"]["problems"]:
        cid = p.get("contestId")
        if cid is None or "rating" not in p or cid in hold:
            continue
        key = f"{cid}-{p['index']}"
        if key in already or not (RATING_LO <= p["rating"] <= RATING_HI):
            continue
        if stats.get(key, 0) < MIN_SOLVERS:
            continue
        base.append({
            "key": key, "name": p["name"], "rating": p["rating"],
            "tags": p.get("tags", []), "solvers": stats.get(key, 0),
            "year": year.get(cid, 0),
            "url": f"https://codeforces.com/problemset/problem/{cid}/{p['index']}",
        })

    # Walk the age tiers, widening only once a tier is fully consumed.
    for ti in range(state.get("tier", 0), len(AGE_TIERS)):
        pool = [p for p in base if p["year"] >= AGE_TIERS[ti]]
        if pool:
            state["tier"] = ti
            print(f"[info] tier {ti} (year >= {AGE_TIERS[ti]}), {len(pool)} candidates, "
                  f"holding back {sorted(hold_names.items())}")
            return random.choice(pool)
    raise SystemExit("No eligible problems remain in any tier.")


def due_slot(now, state):
    """Latest slot today that is due and has not been sent yet.

    GitHub's scheduled runs are best-effort and routinely skip whole hours,
    so keying off the current hour alone silently drops sends. Instead we
    fire the most recent slot that is past due and unsent, which means a run
    landing late still delivers the mail it owed.
    """
    done = set(state.get("sent_slots", {}).get(now.date().isoformat(), []))
    # The day's problem outranks every reminder. If it is still owed and its
    # hour has passed, send it no matter how late the run is -- otherwise a
    # run that lands in the afternoon would resolve to a reminder slot and
    # the problem itself would never go out that day.
    if NEW_SLOT not in done and now.hour >= NEW_SLOT:
        return NEW_SLOT
    # Reminders are time-sensitive -- one that is hours stale is noise, so
    # they only catch up within a short grace window.
    due = [h for h in sorted(SLOTS)
           if h <= now.hour <= h + FOLLOWUP_GRACE and h not in done]
    return max(due) if due else None


# ---------------- leetcode (the Easy that rides along) ----------------

LC_GQL = "https://leetcode.com/graphql"
LC_HEADERS = {
    "Content-Type": "application/json",
    "Referer": "https://leetcode.com/",
    "User-Agent": ("Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) "
                   "AppleWebKit/537.36 (KHTML, like Gecko) Chrome/124 Safari/537.36"),
}
LC_LIST_Q = """query pl($categorySlug: String, $limit: Int, $skip: Int, $filters: QuestionListFilterInput) {
  problemsetQuestionList: questionList(categorySlug: $categorySlug, limit: $limit, skip: $skip, filters: $filters) {
    total: totalNum
    questions: data { questionFrontendId title titleSlug difficulty isPaidOnly topicTags { name } }
  } }"""


def lc_gql(variables):
    payload = json.dumps({"query": LC_LIST_Q, "variables": variables}).encode()
    req = urllib.request.Request(LC_GQL, data=payload, headers=LC_HEADERS)
    with urllib.request.urlopen(req, timeout=30) as r:
        body = json.load(r)
    if "errors" in body:
        raise RuntimeError(body["errors"])
    return body["data"]["problemsetQuestionList"]


def random_lc_easy(seen, attempts=25):
    """A free Easy he has not been sent before."""
    # "algorithms" excludes the SQL, shell and JavaScript-only categories,
    # which are not what he is practising for.
    base = {"categorySlug": "algorithms", "filters": {"difficulty": "EASY"}}
    total = lc_gql({**base, "limit": 1, "skip": 0})["total"]
    for _ in range(attempts):
        qs = lc_gql({**base, "limit": 1, "skip": random.randrange(total)})["questions"]
        if not qs:
            continue
        q = qs[0]
        if q["isPaidOnly"] or q["titleSlug"] in seen:
            continue
        return {"id": q["questionFrontendId"], "title": q["title"], "slug": q["titleSlug"],
                "tags": [t["name"] for t in q.get("topicTags", [])],
                "url": f"https://leetcode.com/problems/{q['titleSlug']}/"}
    raise RuntimeError(f"no unseen free Easy found in {attempts} attempts")


# ---------------- email ----------------

def render(kind, problem, alert_problem, day):
    """Returns (subject, plaintext, html)."""
    blocks, text = [], []

    if kind == "red":
        subject = "RED ALERT: unsubmitted problem"
        text.append(RED_ALERT_BODY)
        text.append(f"\nOutstanding: {alert_problem['name']}\n{alert_problem['url']}")
        blocks.append(
            '<div style="border:2px solid #dc2626;background:#fef2f2;color:#991b1b;'
            'padding:16px;border-radius:8px;font-weight:700;letter-spacing:.02em;'
            f'line-height:1.5">{html.escape(RED_ALERT_BODY)}</div>'
            f'<p style="margin:14px 0 0;font-size:14px">Outstanding: '
            f'<a href="{html.escape(alert_problem["url"])}">{html.escape(alert_problem["name"])}</a></p>')

    elif kind == "followup":
        subject = "Reminder: today's problem is still unsubmitted"
        text.append(MSG_FOLLOWUP)
        text.append(f"\n{problem['name']}\n{problem['url']}")
        blocks.append(
            f'<p style="font-size:15px;line-height:1.65;margin:0">{html.escape(MSG_FOLLOWUP)}</p>'
            f'<p style="margin:16px 0 0"><a href="{html.escape(problem["url"])}" '
            'style="display:inline-block;background:#2563eb;color:#fff;padding:11px 22px;'
            f'border-radius:6px;text-decoration:none;font-weight:600">{html.escape(problem["name"])}</a></p>')

    else:  # new problem of the day
        subject = f"POTD: {problem['name']} (CF {problem['rating']})"
        if alert_problem:
            text.append(RED_ALERT_BODY)
            text.append(f"\nOutstanding: {alert_problem['name']}\n{alert_problem['url']}\n")
            blocks.append(
                '<div style="border:2px solid #dc2626;background:#fef2f2;color:#991b1b;'
                'padding:16px;border-radius:8px;font-weight:700;letter-spacing:.02em;'
                f'line-height:1.5;margin-bottom:24px">{html.escape(RED_ALERT_BODY)}'
                f'<div style="font-weight:400;font-size:13px;margin-top:8px">Outstanding: '
                f'<a href="{html.escape(alert_problem["url"])}" style="color:#991b1b">'
                f'{html.escape(alert_problem["name"])}</a></div></div>')
        tags = ", ".join(problem["tags"]) if problem["tags"] else "—"
        text.append(MSG_NEW)
        text.append(f"\n{problem['name']}  (Codeforces {problem['rating']})\n{problem['url']}\nTopics: {tags}")
        blocks.append(
            f'<p style="font-size:15px;line-height:1.65;margin:0 0 24px">{html.escape(MSG_NEW)}</p>'
            f'<h1 style="font-size:22px;margin:0 0 4px">{html.escape(problem["name"])}</h1>'
            f'<div style="color:#6b7280;font-size:14px;margin-bottom:18px">Codeforces &middot; '
            f'rated {problem["rating"]} &middot; {problem["solvers"]:,} solvers</div>'
            f'<a href="{html.escape(problem["url"])}" style="display:inline-block;background:#2563eb;'
            'color:#fff;padding:11px 22px;border-radius:6px;text-decoration:none;font-weight:600">'
            'Open the problem</a>'
            f'<p style="margin:20px 0 0;font-size:14px;color:#6b7280">Topics: {html.escape(tags)}</p>')

        easy = problem.get("lc_easy")
        if easy:
            etags = ", ".join(easy["tags"]) if easy["tags"] else "\u2014"
            text.append(f"\nAnd today's LeetCode Easy:\n{easy['id']}. {easy['title']}\n"
                        f"{easy['url']}\nTopics: {etags}")
            blocks.append(
                '<hr style="border:0;border-top:1px solid #e5e7eb;margin:28px 0">'
                '<div style="font-size:12px;letter-spacing:.08em;text-transform:uppercase;'
                'color:#6b7280;margin-bottom:10px">And today\'s LeetCode Easy</div>'
                f'<h2 style="font-size:18px;margin:0 0 4px">{html.escape(easy["id"])}. '
                f'{html.escape(easy["title"])}</h2>'
                '<div style="color:#6b7280;font-size:14px;margin-bottom:16px">LeetCode &middot; '
                '<span style="color:#16a34a;font-weight:600">Easy</span></div>'
                f'<a href="{html.escape(easy["url"])}" style="display:inline-block;background:#16a34a;'
                'color:#fff;padding:9px 18px;border-radius:6px;text-decoration:none;font-weight:600">'
                'Open the Easy</a>'
                f'<p style="margin:16px 0 0;font-size:14px;color:#6b7280">Topics: {html.escape(etags)}</p>')

    body = ("<div style=\"font-family:-apple-system,Segoe UI,Roboto,Helvetica,sans-serif;"
            "max-width:540px;margin:0 auto;padding:24px;color:#111827\">"
            f"<div style=\"font-size:12px;letter-spacing:.08em;text-transform:uppercase;"
            f"color:#6b7280;margin-bottom:14px\">{html.escape(day)}</div>"
            + "".join(blocks) +
            "<p style=\"margin-top:30px;font-size:12px;color:#9ca3af\">"
            "Automated by your brother. Reply STOP to end these.</p></div>")
    return subject, "\n".join(text) + "\n\nReply STOP to end these.\n", body


def send(subject, text, body, to):
    user, pw = os.environ.get("GMAIL_USER"), os.environ.get("GMAIL_APP_PASSWORD")
    if not user or not pw:
        raise SystemExit("GMAIL_USER / GMAIL_APP_PASSWORD not set")
    msg = EmailMessage()
    msg["Subject"], msg["From"], msg["To"] = subject, user, to
    msg.set_content(text)
    msg.add_alternative(body, subtype="html")
    with smtplib.SMTP_SSL("smtp.gmail.com", 465, context=ssl.create_default_context()) as s:
        s.login(user, pw)
        s.send_message(msg)


# ---------------- main ----------------

def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--to", default=os.environ.get("RECIPIENT", ""))
    ap.add_argument("--handle", default=os.environ.get("CF_HANDLE", ""))
    ap.add_argument("--dry-run", action="store_true")
    ap.add_argument("--force-hour", type=int, help="pretend it is this Indiana hour")
    a = ap.parse_args()

    now = datetime.datetime.now(TZ)
    today = now.date()
    state = load_state()

    if a.force_hour is not None:
        hour = a.force_hour
    else:
        hour = due_slot(now, state)
        if hour is None:
            print(f"[skip] {now:%Y-%m-%d %H:%M %Z}: nothing due")
            return
        if hour != now.hour:
            print(f"[catch-up] the {hour:02d}:00 slot was missed; sending at {now:%H:%M %Z}")

    handle = a.handle.strip()

    # Yesterday's problem is the only one eligible for a red alert.
    y_key = (today - datetime.timedelta(days=1)).isoformat()
    yesterday = state["assigned"].get(y_key)
    alert = None
    if yesterday and handle:
        if yesterday["key"] not in solved_set(handle):
            alert = yesterday

    if SLOTS[hour] == "new":
        rec = state["assigned"].get(today.isoformat())
        if not rec:
            rec = pick_problem(state, handle)
            state["assigned"][today.isoformat()] = rec
            state["sent_keys"].append(rec["key"])
            # Keep only a fortnight of assignments; sent_keys is the durable record.
            for k in [k for k in state["assigned"] if k < (today - datetime.timedelta(days=14)).isoformat()]:
                del state["assigned"][k]
        if not rec.get("lc_easy"):
            # A LeetCode outage must not cost him his Codeforces problem.
            try:
                rec["lc_easy"] = random_lc_easy(set(state.setdefault("lc_sent_slugs", [])))
                state["lc_sent_slugs"].append(rec["lc_easy"]["slug"])
                state["assigned"][today.isoformat()] = rec
            except Exception as e:
                print(f"[warn] no LeetCode Easy this morning: {e}", file=sys.stderr)
        kind, problem = "new", rec

    else:
        if not handle:
            print("[skip] no CF_HANDLE set -- follow-ups disabled until a handle is configured")
            return
        today_rec = state["assigned"].get(today.isoformat())
        if alert:
            kind, problem = "red", None
        elif today_rec and today_rec["key"] not in solved_set(handle):
            kind, problem = "followup", today_rec
        else:
            print("[skip] nothing outstanding")
            return

    subject, text, body = render(kind, problem, alert, today.isoformat())

    if a.dry_run or not a.to:
        print(f"--- {now:%Y-%m-%d %H:%M %Z} | slot {hour} | kind={kind} | handle={handle or '(none)'}")
        print("Subject:", subject)
        print("-" * 60)
        print(text)
    else:
        send(subject, text, body, a.to)
        print(f"[sent] {kind} -> {a.to}: {subject}")
        slots = state.setdefault("sent_slots", {}).setdefault(today.isoformat(), [])
        if hour not in slots:
            slots.append(hour)
        cutoff = (today - datetime.timedelta(days=14)).isoformat()
        for k in [k for k in state["sent_slots"] if k < cutoff]:
            del state["sent_slots"][k]
        save_state(state)
        return

    # A dry run must not consume a problem or mark it sent.
    print("[dry-run] state left unchanged")


if __name__ == "__main__":
    main()
