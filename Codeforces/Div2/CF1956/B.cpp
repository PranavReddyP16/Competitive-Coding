#include<iostream>
#include<vector>
using namespace std;
#define int long long
void solve() {
    int n,m; cin>>n>>m;
    vector<string> grid(n);
    for(auto& s:grid) cin>>s;
    int cnt=0;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++)
        if((i+j)%2==0) cnt+=(grid[i][j]=='#');
    cout<<cnt<<"\n";
}
signed main() { int t; cin>>t; while(t--) solve(); }
// 4893
// 4516
