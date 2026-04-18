#include<bits/stdc++.h>
using namespace std;
#define int long long

struct SegTree {
    int n;
    vector<int> tree;
    SegTree(int n) : n(n), tree(4*n, 0) {}
    void build(vector<int>& a, int v, int tl, int tr) {
        if(tl==tr) { tree[v]=a[tl]; return; }
        int tm=(tl+tr)/2;
        build(a,2*v,tl,tm); build(a,2*v+1,tm+1,tr);
        tree[v]=tree[2*v]+tree[2*v+1];
    }
    void update(int v, int tl, int tr, int pos, int val) {
        if(tl==tr) { tree[v]=val; return; }
        int tm=(tl+tr)/2;
        if(pos<=tm) update(2*v,tl,tm,pos,val);
        else update(2*v+1,tm+1,tr,pos,val);
        tree[v]=tree[2*v]+tree[2*v+1];
    }
    int query(int v, int tl, int tr, int l, int r) {
        if(l>r) return 0;
        if(l==tl && r==tr) return tree[v];
        int tm=(tl+tr)/2;
        return query(2*v,tl,tm,l,min(r,tm))+query(2*v+1,tm+1,tr,max(l,tm+1),r);
    }
};

signed main() {
    int n,q; cin>>n>>q;
    vector<int> a(n); for(auto& x:a) cin>>x;
    SegTree st(n);
    st.build(a,1,0,n-1);
    while(q--) {
        int type; cin>>type;
        if(type==1) { int p,v; cin>>p>>v; st.update(1,0,n-1,p,v); }
        else { int l,r; cin>>l>>r; cout<<st.query(1,0,n-1,l,r)<<"\n"; }
    }
}
// optimized
// 4520000
// 7150000
// 6408000
// 7091000
// 7260000
// 3920000
// 5380000
// 3165000
// 455496340
// 1098846362
// 3737425311
// 1364893929
// 1194524768
// 1180491284
// 388056394
// 3042289838
// 2698775985
// 3358286175
// 2720892134
// 488295601
// 3265344976
// 7293
// Added: support for walk/descent queries
// Alternative: iterative implementation for 2x speed
// Tip: can be persistent with path copying
