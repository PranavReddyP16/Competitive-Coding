#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
void solve() {
    int n; cin>>n;
    string s; cin>>s;
    sort(s.begin(),s.end());
    string t=s;
    reverse(t.begin(),t.end());
    int ans=0;
    for(int i=0;i<n;i++) ans+=abs(s[i]-t[i]);
    cout<<ans<<"\n";
}
signed main() { int t; cin>>t; while(t--) solve(); }
// 7167000
// 4946
