#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<int> bfs(int src, vector<vector<int>>& adj, int n) {
    vector<int> dist(n, -1);
    queue<int> q;
    dist[src]=0; q.push(src);
    while(!q.empty()) {
        int u=q.front(); q.pop();
        for(int v:adj[u]) if(dist[v]==-1) { dist[v]=dist[u]+1; q.push(v); }
    }
    return dist;
}

vector<int> dijkstra(int src, vector<vector<pair<int,int>>>& adj, int n) {
    vector<int> dist(n, 1e18);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
    dist[src]=0; pq.push({0,src});
    while(!pq.empty()) {
        auto [d,u]=pq.top(); pq.pop();
        if(d>dist[u]) continue;
        for(auto [v,w]:adj[u]) if(dist[u]+w<dist[v]) {
            dist[v]=dist[u]+w; pq.push({dist[v],v});
        }
    }
    return dist;
}

signed main() {
    int n,m,src; cin>>n>>m>>src;
    vector<vector<pair<int,int>>> adj(n);
    for(int i=0;i<m;i++) { int u,v,w; cin>>u>>v>>w; adj[u].push_back({v,w}); }
    auto dist=dijkstra(src,adj,n);
    for(int i=0;i<n;i++) cout<<dist[i]<<" ";
}
// new year cleanup
// 2507000
// 3792000
// 3570000
// 7925000
// 1151000
// 6939000
// 1960000
// 7672000
// 5333000
// 5130000
// 1263336937
// 1821185095
// 2017549434
// 2148975550
// 780867057
// 383991463
// 1673326463
// 4208053251
// 2064383699
// 265549239
// 3048898793
// 4232466805
// 1903177713
// 1671630125
// 3446100016
// 2525106882
// 3141710183
// Extension: works with any associative operation
