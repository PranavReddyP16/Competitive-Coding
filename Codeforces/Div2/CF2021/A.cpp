#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
void solve() {
    int n; cin>>n;
    vector<int> a(n); for(auto& x:a) cin>>x;
    sort(a.begin(),a.end());
    if(n%2) cout<<a[n/2]<<"\n";
    else cout<<(a[n/2-1]+a[n/2])/2<<"\n";
}
signed main() { int t; cin>>t; while(t--) solve(); }
// 3256000
// 2396
// 6964
// 4004
