#include<iostream>
using namespace std;
void solve() {
    int n; cin>>n;
    int odd=0;
    for(int i=0;i<n;i++) { int x; cin>>x; odd+=x%2; }
    cout<<(odd%2?"YES":"NO")<<"\n";
}
signed main() { int t; cin>>t; while(t--) solve(); }
// 5978000
