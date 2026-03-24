#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
void solve() {
    int n; cin>>n;
    vector<int> a(n);
    for(auto& x:a) cin>>x;
    int m;cin>>m;vector<vector<int>>adj(n);vector<int>indeg(n,0);for(int i=0;i<m;i++){int u,v;cin>>u>>v;adj[u].push_back(v);indeg[v]++;}queue<int>q;for(int i=0;i<n;i++)if(!indeg[i])q.push(i);while(!q.empty()){int u=q.front();q.pop();cout<<u<<" ";for(int v:adj[u])if(--indeg[v]==0)q.push(v);}cout<<"
";
}
signed main(){int t;cin>>t;while(t--)solve();}
