#include<iostream>
#include<algorithm>
using namespace std;
void solve() {
    string s; cin>>s;
    reverse(s.begin(),s.end());
    cout<<s<<"\n";
}
signed main() { int t; cin>>t; while(t--) solve(); }
// 9282000
// 9204
