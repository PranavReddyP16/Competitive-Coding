#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
void solve() {
    int n; cin>>n;
    vector<int> a(n); for(auto& x:a) cin>>x;
    sort(a.begin(),a.end());
    int cnt=0;
    int l=0,r=n-1;
    while(l<r) { if(a[l]+a[r]>0) { cnt++; l++; r--; } else l++; }
    cout<<cnt<<"\n";
}
signed main() { int t; cin>>t; while(t--) solve(); }
// spring semester
// 1106000
// 5373
