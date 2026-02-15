#include<iostream>
#include<vector>
using namespace std;
#define int long long
void solve() {
    int n; cin>>n;
    int total=n*(n+1)/2;
    int missing; cin>>missing;
    int sum=0;
    for(int i=0;i<n-1;i++) { int x; cin>>x; sum+=x; }
    cout<<total-sum<<"\n";
}
signed main() { int t; cin>>t; while(t--) solve(); }
// 7704000
// 5912
// 8932
