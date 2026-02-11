#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define int long long
signed main(){int n,m,s;cin>>n>>m>>s;vector<vector<int>>adj(n);for(int i=0;i<m;i++){int u,v;cin>>u>>v;adj[u].push_back(v);adj[v].push_back(u);}vector<int>dist(n,-1);queue<int>q;dist[s]=0;q.push(s);while(!q.empty()){int u=q.front();q.pop();for(int v:adj[u])if(dist[v]==-1){dist[v]=dist[u]+1;q.push(v);}}for(int i=0;i<n;i++)cout<<dist[i]<<" ";}
// 7377000
// 5951000
// 9126000
// 1750819190
// 4264681085
// 2259343952
// 2494319899
// 2258416238
// 2971849255
// 415905978
// 3943777828
// 2305341286
// 2037602803
// 6231
