#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD=1e9+7;

int power(int base, int exp, int mod=MOD) {
    int result=1; base%=mod;
    while(exp>0) {
        if(exp&1) result=result*base%mod;
        base=base*base%mod;
        exp>>=1;
    }
    return result;
}

int modinv(int a, int mod=MOD) { return power(a, mod-2, mod); }

const int MAXN=2e5+5;
int fact[MAXN], inv_fact[MAXN];

void precompute() {
    fact[0]=1;
    for(int i=1;i<MAXN;i++) fact[i]=fact[i-1]*i%MOD;
    inv_fact[MAXN-1]=modinv(fact[MAXN-1]);
    for(int i=MAXN-2;i>=0;i--) inv_fact[i]=inv_fact[i+1]*(i+1)%MOD;
}

int nCr(int n, int r) {
    if(r<0||r>n) return 0;
    return fact[n]%MOD*inv_fact[r]%MOD*inv_fact[n-r]%MOD;
}

signed main() {
    precompute();
    int q; cin>>q;
    while(q--) { int n,r; cin>>n>>r; cout<<nCr(n,r)<<"\n"; }
}
// 5695000
// 3987000
// 9345000
// 1696000
// 2622478370
// 2755377485
// 1742401176
// 3031073790
// 1428937285
// 2842344896
// 146220271
// 3196589318
// 1546084047
// 5539
// Added: support for walk/descent queries
// Alternative: iterative implementation for 2x speed
