#include<iostream>
#include<vector>
using namespace std;
#define int long long
void solve() {
    int n; cin>>n;
    vector<int> a(n); for(auto& x:a) cin>>x;
    int mx=0;
    for(int i=1;i<n;i++) mx=max(mx,abs(a[i]-a[i-1]));
    cout<<mx<<"\n";
}
signed main() { int t; cin>>t; while(t--) solve(); }
// 4861000
// 1302
// 7336
