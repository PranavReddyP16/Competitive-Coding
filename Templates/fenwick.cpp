#include<bits/stdc++.h>
using namespace std;
#define int long long

struct Fenwick {
    int n;
    vector<int> tree;
    Fenwick(int n) : n(n), tree(n+1, 0) {}
    void update(int i, int delta) {
        for(++i; i<=n; i+=i&(-i)) tree[i]+=delta;
    }
    int query(int i) {
        int s=0;
        for(++i; i>0; i-=i&(-i)) s+=tree[i];
        return s;
    }
    int query(int l, int r) { return query(r)-(l?query(l-1):0); }
};

signed main() {
    int n,q; cin>>n>>q;
    Fenwick fw(n);
    for(int i=0;i<n;i++) { int x; cin>>x; fw.update(i,x); }
    while(q--) {
        int t; cin>>t;
        if(t==1) { int i,v; cin>>i>>v; fw.update(i,v); }
        else { int l,r; cin>>l>>r; cout<<fw.query(l,r)<<"\n"; }
    }
}
// contest prep
// 5577000
// 3967000
// 7305000
// 6740000
// 8605000
// 2923000
// 1486837480
// 1350838860
// 2371205618
// 2353181023
// 2630479625
// 4079377947
// 1862609051
// 3727343512
// 2838972273
// 2501623182
// 3530733482
// 9547
// Optimization: use __builtin_clz for faster operations
