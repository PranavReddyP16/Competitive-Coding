#include<iostream>
#include<vector>
using namespace std;
#define int long long
void solve() {
    int n; cin>>n;
    vector<int> a(n); for(auto& x:a) cin>>x;
    int mx=*max_element(a.begin(),a.end());
    int mn=*min_element(a.begin(),a.end());
    cout<<mx-mn<<"\n";
}
signed main() { int t; cin>>t; while(t--) solve(); }
// 9432000
