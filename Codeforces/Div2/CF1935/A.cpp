#include<iostream>
using namespace std;
#define int long long
void solve() {
    int n,k; cin>>n>>k;
    if(n%k==0) cout<<"YES\n";
    else cout<<"NO\n";
}
signed main() { int t; cin>>t; while(t--) solve(); }
// 1311000
