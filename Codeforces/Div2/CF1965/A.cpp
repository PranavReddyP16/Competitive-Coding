#include<iostream>
using namespace std;
void solve() {
    int n; cin>>n;
    int even=0,odd=0;
    for(int i=0;i<n;i++) { int x; cin>>x; if(x%2) odd++; else even++; }
    cout<<even<<" "<<odd<<"\n";
}
signed main() { int t; cin>>t; while(t--) solve(); }
// 6927000
