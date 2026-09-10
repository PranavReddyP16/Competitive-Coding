#!/usr/bin/env python3
"""LeetCode problem of the day mailer.

Sends one email each morning at 08:00 America/New_York. No follow-ups.

Problem selection: if LeetCode's own daily challenge is a Medium, use it --
that way she is working the same problem as everyone else that day, and the
discussion tab is full of same-day activity. Otherwise fall back to a random
unseen Medium.
"""
import argparse, datetime, html, json, os, random, smtplib, ssl, sys, urllib.request
from email.message import EmailMessage
from zoneinfo import ZoneInfo

TZ = ZoneInfo("America/New_York")
SEND_HOUR = 8
GQL = "https://leetcode.com/graphql"
HEADERS = {
    "Content-Type": "application/json",
    "Referer": "https://leetcode.com/",
    "User-Agent": ("Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) "
                   "AppleWebKit/537.36 (KHTML, like Gecko) Chrome/124 Safari/537.36"),
}
STATE = os.path.join(os.path.dirname(os.path.abspath(__file__)), "lc_state.json")

MSG_NEW = (
    "Here is your problem of the day! This is your highest priority item to "
    "complete today. If you have to choose between this and saying goodbye to "
    "your loved ones in case of an apocalyptic-level cataclysm, you should be "
    "aiming for an AC. AI submissions will not be tolerated. Happy coding!"
)


def gql(query, variables=None):
    payload = json.dumps({"query": query, "variables": variables or {}}).encode()
    req = urllib.request.Request(GQL, data=payload, headers=HEADERS)
    with urllib.request.urlopen(req, timeout=30) as r:
        body = json.load(r)
    if "errors" in body:
        raise SystemExit(f"LeetCode GraphQL error: {body['errors']}")
    return body["data"]


DAILY_Q = """query { activeDailyCodingChallengeQuestion { date link question {
  questionFrontendId title titleSlug difficulty isPaidOnly topicTags { name } } } }"""

LIST_Q = """query pl($categorySlug: String, $limit: Int, $skip: Int, $filters: QuestionListFilterInput) {
  problemsetQuestionList: questionList(categorySlug: $categorySlug, limit: $limit, skip: $skip, filters: $filters) {
    total: totalNum
    questions: data { questionFrontendId title titleSlug difficulty isPaidOnly acRate topicTags { name } }
  } }"""


def load_state():
    try:
        with open(STATE) as f:
            return json.load(f)
    except (OSError, ValueError):
        return {"sent_slugs": [], "assigned": {}}


def save_state(s):
    with open(STATE, "w") as f:
        json.dump(s, f, indent=2, sort_keys=True)
        f.write("\n")


def shape(q, is_daily):
    return {
        "id": q["questionFrontendId"], "title": q["title"], "slug": q["titleSlug"],
        "difficulty": q["difficulty"], "is_daily": is_daily,
        "tags": [t["name"] for t in q.get("topicTags", [])],
        "url": f"https://leetcode.com/problems/{q['titleSlug']}/",
    }


def daily_medium():
    d = gql(DAILY_Q)["activeDailyCodingChallengeQuestion"]
    q = d["question"]
    if q["difficulty"] == "Medium" and not q["isPaidOnly"]:
        return shape(q, True)
    print(f"[info] LeetCode daily is {q['difficulty']}"
          f"{' (premium)' if q['isPaidOnly'] else ''} -- falling back to a random Medium")
    return None


def random_medium(seen, attempts=25):
    total = gql(LIST_Q, {"categorySlug": "", "limit": 1, "skip": 0,
                         "filters": {"difficulty": "MEDIUM"}})["problemsetQuestionList"]["total"]
    for _ in range(attempts):
        skip = random.randrange(total)
        qs = gql(LIST_Q, {"categorySlug": "", "limit": 1, "skip": skip,
                          "filters": {"difficulty": "MEDIUM"}})["problemsetQuestionList"]["questions"]
        if not qs:
            continue
        q = qs[0]
        if q["isPaidOnly"] or q["titleSlug"] in seen:
            continue
        return shape(q, False)
    raise SystemExit(f"Could not find an unseen free Medium in {attempts} attempts.")


def render(p, day):
    tags = ", ".join(p["tags"]) if p["tags"] else "—"
    badge = "LeetCode Daily Challenge" if p["is_daily"] else "LeetCode"
    subject = f"POTD: {p['title']} (LeetCode Medium)"
    text = (f"{MSG_NEW}\n\n{p['title']}  ({badge} · Medium)\n{p['url']}\n"
            f"Topics: {tags}\n\nReply STOP to end these.\n")
    body = f"""<div style="font-family:-apple-system,Segoe UI,Roboto,Helvetica,sans-serif;max-width:540px;margin:0 auto;padding:24px;color:#111827">
<div style="font-size:12px;letter-spacing:.08em;text-transform:uppercase;color:#6b7280;margin-bottom:14px">{html.escape(day)}</div>
<p style="font-size:15px;line-height:1.65;margin:0 0 24px">{html.escape(MSG_NEW)}</p>
<h1 style="font-size:22px;margin:0 0 4px">{html.escape(p['id'])}. {html.escape(p['title'])}</h1>
<div style="color:#6b7280;font-size:14px;margin-bottom:18px">{html.escape(badge)} &middot;
<span style="color:#d97706;font-weight:600">Medium</span></div>
<a href="{html.escape(p['url'])}" style="display:inline-block;background:#f59e0b;color:#111827;padding:11px 22px;border-radius:6px;text-decoration:none;font-weight:700">Open the problem</a>
<p style="margin:20px 0 0;font-size:14px;color:#6b7280">Topics: {html.escape(tags)}</p>
<p style="margin-top:30px;font-size:12px;color:#9ca3af">Automated by your brother. Reply STOP to end these.</p></div>"""
    return subject, text, body


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


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--to", default=os.environ.get("RECIPIENT_LC", ""))
    ap.add_argument("--dry-run", action="store_true")
    ap.add_argument("--force-hour", type=int)
    a = ap.parse_args()

    now = datetime.datetime.now(TZ)
    today = now.date().isoformat()
    state = load_state()

    # GitHub's scheduled runs routinely skip whole hours, so rather than
    # requiring a run to land inside the 08:00 hour, send whenever today's
    # mail is still owed and 08:00 has passed.
    if a.force_hour is not None:
        if a.force_hour != SEND_HOUR:
            print(f"[skip] forced hour {a.force_hour} is not the {SEND_HOUR:02d}:00 slot")
            return
    else:
        if now.hour < SEND_HOUR:
            print(f"[skip] {now:%Y-%m-%d %H:%M %Z} is before the {SEND_HOUR:02d}:00 slot")
            return
        if today in state.get("assigned", {}):
            print(f"[skip] already sent today ({today})")
            return
        if now.hour != SEND_HOUR:
            print(f"[catch-up] the {SEND_HOUR:02d}:00 slot was missed; sending at {now:%H:%M %Z}")

    pick = state["assigned"].get(today)
    if not pick:
        pick = daily_medium() or random_medium(set(state["sent_slugs"]))

    subject, text, body = render(pick, today)

    if a.dry_run or not a.to:
        print(f"--- {now:%Y-%m-%d %H:%M %Z} | daily={pick['is_daily']}")
        print("Subject:", subject)
        print("-" * 60)
        print(text)
        print("[dry-run] state left unchanged")
        return

    send(subject, text, body, a.to)
    print(f"[sent] -> {a.to}: {subject}")
    state["assigned"][today] = pick
    if pick["slug"] not in state["sent_slugs"]:
        state["sent_slugs"].append(pick["slug"])
    cutoff = (now.date() - datetime.timedelta(days=14)).isoformat()
    for k in [k for k in state["assigned"] if k < cutoff]:
        del state["assigned"][k]
    save_state(state)


if __name__ == "__main__":
    main()
