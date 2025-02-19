#include<iostream>
using namespace std;
void solve() {
    int n; cin>>n;
    string s; cin>>s;
    int ones=0;
    for(char c:s) ones+=(c=='1');
    cout<<(ones%2?"Alice":"Bob")<<"\n";
}
signed main() { int t; cin>>t; while(t--) solve(); }
// 2181000
