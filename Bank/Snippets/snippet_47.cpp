#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
void solve() {
    int n; cin>>n;
    vector<int> a(n);
    for(auto& x:a) cin>>x;
    int m,s;cin>>m>>s;vector<vector<int>>adj(n);for(int i=0;i<m;i++){int u,v;cin>>u>>v;adj[u].push_back(v);adj[v].push_back(u);}vector<int>dist(n,-1);queue<int>q;dist[s]=0;q.push(s);while(!q.empty()){int u=q.front();q.pop();for(int v:adj[u])if(dist[v]==-1){dist[v]=dist[u]+1;q.push(v);}}for(int i=0;i<n;i++)cout<<dist[i]<<" ";cout<<"
";
}
signed main(){int t;cin>>t;while(t--)solve();}
// 1136
