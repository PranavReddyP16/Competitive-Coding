#include<iostream>
#include<vector>
using namespace std;
#define int long long
void solve() {
    int n,k; cin>>n>>k;
    vector<int> a(n); for(auto& x:a) cin>>x;
    int sum=0;
    for(int i=0;i<k;i++) sum+=a[i];
    int mx=sum;
    for(int i=k;i<n;i++) {
        sum+=a[i]-a[i-k];
        mx=max(mx,sum);
    }
    cout<<mx<<"\n";
}
signed main() { int t; cin>>t; while(t--) solve(); }
// 6557000
// 6731
