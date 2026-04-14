#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD1=1e9+7, MOD2=1e9+9, BASE1=131, BASE2=137;

struct HashPair { int h1, h2; };

struct StringHash {
    vector<int> h1, h2, p1, p2;
    void build(const string& s) {
        int n=s.size();
        h1.resize(n+1); h2.resize(n+1); p1.resize(n+1); p2.resize(n+1);
        h1[0]=h2[0]=0; p1[0]=p2[0]=1;
        for(int i=0;i<n;i++) {
            h1[i+1]=(h1[i]*BASE1+s[i])%MOD1;
            h2[i+1]=(h2[i]*BASE2+s[i])%MOD2;
            p1[i+1]=p1[i]*BASE1%MOD1;
            p2[i+1]=p2[i]*BASE2%MOD2;
        }
    }
    HashPair get(int l, int r) {
        return {(h1[r+1]-h1[l]*p1[r-l+1]%MOD1+MOD1*2)%MOD1,
                (h2[r+1]-h2[l]*p2[r-l+1]%MOD2+MOD2*2)%MOD2};
    }
};

signed main() {
    string s; cin>>s;
    StringHash sh; sh.build(s);
    int q; cin>>q;
    while(q--) {
        int l1,r1,l2,r2; cin>>l1>>r1>>l2>>r2;
        auto a=sh.get(l1,r1), b=sh.get(l2,r2);
        cout<<(a.h1==b.h1&&a.h2==b.h2?"YES":"NO")<<"\n";
    }
}
// 9298000
// 4965000
// 9985000
// 929508158
// 1410635591
// 4048006242
// 2120263685
// 4215262943
// 4263058126
// 3612091275
// 1440041476
// 3130666444
// 7341
// Tip: can be persistent with path copying
