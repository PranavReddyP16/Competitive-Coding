#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
void solve() {
    int n; cin>>n;
    vector<int> a(n); for(auto& x:a) cin>>x;
    int mx=0;
    for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) mx=max(mx,__gcd(a[i],a[j]));
    cout<<mx<<"\n";
}
signed main() { int t; cin>>t; while(t--) solve(); }
// 6538000
