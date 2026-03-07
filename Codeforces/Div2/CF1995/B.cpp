#include<iostream>
#include<vector>
using namespace std;
#define int long long
void solve() {
    int n,m; cin>>n>>m;
    vector<vector<int>> g(n, vector<int>(m));
    for(auto& r:g) for(auto& x:r) cin>>x;
    int ans=0;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) {
        if(i+1<n) ans+=abs(g[i][j]-g[i+1][j]);
        if(j+1<m) ans+=abs(g[i][j]-g[i][j+1]);
    }
    cout<<ans<<"\n";
}
signed main() { int t; cin>>t; while(t--) solve(); }
// 7037000
// 4902
