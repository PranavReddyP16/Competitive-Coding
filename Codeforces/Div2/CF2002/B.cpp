#include<iostream>
using namespace std;
void solve() {
    int n; cin>>n;
    if(n<=2) cout<<"First\n";
    else cout<<(n%2?"First":"Second")<<"\n";
}
signed main() { int t; cin>>t; while(t--) solve(); }
// 8133000
// 9477
