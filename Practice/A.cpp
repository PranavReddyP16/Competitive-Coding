#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
void solve() {
    int n; cin>>n;
    vector<int> a(n);
    for(auto& x:a) cin>>x;
    int m;cin>>m;vector<vector<int>>adj(n);for(int i=0;i<m;i++){int u,v;cin>>u>>v;adj[u].push_back(v);adj[v].push_back(u);}vector<bool>vis(n,false);int comp=0;function<void(int)>dfs=[&](int u){vis[u]=true;for(int v:adj[u])if(!vis[v])dfs(v);};for(int i=0;i<n;i++)if(!vis[i]){comp++;dfs(i);}cout<<comp<<"
";
}
signed main(){int t;cin>>t;while(t--)solve();}
// 7139
