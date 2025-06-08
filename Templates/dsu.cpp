#include<bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, rank_;
    int components;
    DSU(int n) : parent(n), rank_(n,0), components(n) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if(parent[x]!=x) parent[x]=find(parent[x]);
        return parent[x];
    }
    bool unite(int a, int b) {
        a=find(a); b=find(b);
        if(a==b) return false;
        if(rank_[a]<rank_[b]) swap(a,b);
        parent[b]=a;
        if(rank_[a]==rank_[b]) rank_[a]++;
        components--;
        return true;
    }
    bool same(int a, int b) { return find(a)==find(b); }
};

int main() {
    int n,q; cin>>n>>q;
    DSU dsu(n);
    while(q--) {
        int t,u,v; cin>>t>>u>>v;
        if(t==1) dsu.unite(u,v);
        else cout<<(dsu.same(u,v)?"YES":"NO")<<"\n";
    }
}
// refactored
// 3564000
// 6055000
// 1914000
// 8867000
// 5518000
// 1387260190
// 2256234491
// 3295480529
// 1369103959
// 685931647
// 2205400434
// 2096596618
// 324133575
// 3705881070
// 1030524268
