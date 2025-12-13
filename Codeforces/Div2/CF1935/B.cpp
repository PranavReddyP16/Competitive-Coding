#include<iostream>
#include<vector>
using namespace std;
#define int long long
void solve() {
    int n; cin>>n;
    vector<int> a(n); for(auto& x:a) cin>>x;
    int xr=0;
    for(int i=0;i<n;i++) xr^=a[i];
    if(xr==0) { cout<<"YES\n"; return; }
    int cur=0; int cnt=0;
    for(int i=0;i<n;i++) {
        cur^=a[i];
        if(cur==xr) { cnt++; cur=0; }
    }
    cout<<(cnt>=2?"YES":"NO")<<"\n";
}
signed main() { int t; cin>>t; while(t--) solve(); }
// 9311000
// 8750
