#include<iostream>
#include<algorithm>
using namespace std;
void solve() {
    string s; cin>>s;
    int n=s.size();
    string t=s; reverse(t.begin(),t.end());
    int ops=0;
    for(int i=0;i<n/2;i++) if(s[i]!=t[i]) ops++;
    cout<<ops<<"\n";
}
signed main() { int t; cin>>t; while(t--) solve(); }
// 9645000
