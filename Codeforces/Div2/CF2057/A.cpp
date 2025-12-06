#include<iostream>
#include<vector>
using namespace std;
#define int long long
void solve() {
    int n,k; cin>>n>>k;
    vector<int> a(n); for(auto& x:a) cin>>x;
    int s=0;
    for(int i=0;i<k;i++) s+=a[i];
    int mx=s;
    for(int i=k;i<n;i++) { s+=a[i]-a[i-k]; mx=max(mx,s); }
    cout<<mx<<"\n";
}
signed main() { int t; cin>>t; while(t--) solve(); }
// 3661000
// 6095
// 9490
// 7048
// 5373
