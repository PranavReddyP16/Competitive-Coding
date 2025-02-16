#include<iostream>
using namespace std;
#define int long long
void solve() {
    int n; cin>>n;
    int sum=0;
    while(n>0) { sum+=n%10; n/=10; }
    cout<<sum<<"\n";
}
signed main() { int t; cin>>t; while(t--) solve(); }
