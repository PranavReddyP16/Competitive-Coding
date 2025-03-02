#include<iostream>
#include<vector>
using namespace std;
#define int long long
void solve() {
    int n,k; cin>>n>>k;
    vector<int> a(n); for(auto& x:a) cin>>x;
    int cnt=0;
    for(int x:a) if(x!=k) cnt++;
    cout<<cnt<<"\n";
}
signed main() { int t; cin>>t; while(t--) solve(); }
// 3795000
