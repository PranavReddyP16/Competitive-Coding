#include<iostream>
using namespace std;
#define int long long
void solve() {
    int n; cin>>n;
    string s; cin>>s;
    int cnt=0;
    for(char c:s) if(c=='1') cnt++;
    cout<<min(cnt, n-cnt)<<"\n";
}
signed main() { int t; cin>>t; while(t--) solve(); }
// 6828000
// 5735
