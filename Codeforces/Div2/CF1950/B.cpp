#include<iostream>
#include<string>
using namespace std;
void solve() {
    int n; cin>>n;
    string s; cin>>s;
    int ops=0;
    for(int i=0;i<n-1;i++) if(s[i]!=s[i+1]) ops++;
    cout<<ops<<"\n";
}
signed main() { int t; cin>>t; while(t--) solve(); }
