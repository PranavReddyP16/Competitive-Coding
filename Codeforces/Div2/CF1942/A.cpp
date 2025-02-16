#include<iostream>
using namespace std;
#define int long long
void solve() {
    int n; cin>>n;
    int ans=0;
    while(n>0) { ans+=n%10; n/=10; }
    cout<<ans<<"\n";
}
signed main() { int t; cin>>t; while(t--) solve(); }
// 6013000
