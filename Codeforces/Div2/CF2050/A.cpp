#include<iostream>
using namespace std;
void solve() {
    string s,t; cin>>s>>t;
    int cnt=0;
    for(int i=0;i<(int)min(s.size(),t.size());i++) if(s[i]==t[i]) cnt++;
    cout<<cnt<<"\n";
}
signed main() { int t; cin>>t; while(t--) solve(); }
// 4817000
// 6492
