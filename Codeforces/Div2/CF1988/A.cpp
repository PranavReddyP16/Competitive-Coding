#include<iostream>
#include<vector>
using namespace std;
#define int long long
void solve() {
    int n; cin>>n;
    vector<int> a(n); for(auto& x:a) cin>>x;
    int s1=0,s2=0;
    for(int i=0;i<n;i++) { if(i%2==0) s1+=a[i]; else s2+=a[i]; }
    cout<<abs(s1-s2)<<"\n";
}
signed main() { int t; cin>>t; while(t--) solve(); }
// 7225000
// 6094
