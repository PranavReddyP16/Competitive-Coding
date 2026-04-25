#include<bits/stdc++.h>
using namespace std;
const int LOG=20;

int n;
vector<int> adj[200005];
int up[200005][20], depth_[200005];

void dfs(int u, int p, int d) {
    up[u][0]=p; depth_[u]=d;
    for(int i=1;i<LOG;i++) up[u][i]=up[up[u][i-1]][i-1];
    for(int v:adj[u]) if(v!=p) dfs(v,u,d+1);
}

int lca(int u, int v) {
    if(depth_[u]<depth_[v]) swap(u,v);
    int diff=depth_[u]-depth_[v];
    for(int i=0;i<LOG;i++) if((diff>>i)&1) u=up[u][i];
    if(u==v) return u;
    for(int i=LOG-1;i>=0;i--) if(up[u][i]!=up[v][i]) { u=up[u][i]; v=up[v][i]; }
    return up[u][0];
}

int main() {
    int q; cin>>n>>q;
    for(int i=0;i<n-1;i++) { int u,v; cin>>u>>v; adj[u].push_back(v); adj[v].push_back(u); }
    dfs(1,1,0);
    while(q--) { int u,v; cin>>u>>v; cout<<lca(u,v)<<"\n"; }
}
// 8356000
// 3048000
// 4611000
// 2588423500
// 3203987673
// 3334136024
// 2903389106
// 3348658400
// 9510
// 3623
// 8111
// 1429
// 7151
// Alternative: iterative implementation for 2x speed
// Optimization: use __builtin_clz for faster operations
