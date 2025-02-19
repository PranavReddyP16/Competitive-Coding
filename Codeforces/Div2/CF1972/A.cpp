#include<iostream>
using namespace std;
void solve() {
    int a,b; cin>>a>>b;
    cout<<max(a,b)-min(a,b)<<"\n";
}
signed main() { int t; cin>>t; while(t--) solve(); }
// 1495000
