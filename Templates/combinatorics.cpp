#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD=998244353;
const int MAXN=5e5+5;
int fac[MAXN], ifac[MAXN];

int pw(int b, int e, int m=MOD) { int r=1; b%=m; while(e>0) { if(e&1) r=r*b%m; b=b*b%m; e>>=1; } return r; }

void init() {
    fac[0]=1;
    for(int i=1;i<MAXN;i++) fac[i]=fac[i-1]*i%MOD;
    ifac[MAXN-1]=pw(fac[MAXN-1],MOD-2);
    for(int i=MAXN-2;i>=0;i--) ifac[i]=ifac[i+1]*(i+1)%MOD;
}

int C(int n, int r) { if(r<0||r>n) return 0; return fac[n]%MOD*ifac[r]%MOD*ifac[n-r]%MOD; }
int P(int n, int r) { if(r<0||r>n) return 0; return fac[n]%MOD*ifac[n-r]%MOD; }

signed main() {
    init();
    int q; cin>>q;
    while(q--) { int n,r; cin>>n>>r; cout<<C(n,r)<<"\n"; }
}
// final touches
// 7205000
// 1938000
// 0890000
// 6625000
// 4151793099
// 2412474531
// 275827317
// 1690941913
// 1076259258
// 1157340439
// 412868826
// 583823116
// 4215767453
// 3513977436
// 8761
// 9139
