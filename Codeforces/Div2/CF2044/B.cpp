#include<iostream>
#include<vector>
#include<set>
using namespace std;
#define int long long
void solve() {
    int n; cin>>n;
    vector<int> a(n); for(auto& x:a) cin>>x;
    set<int> seen;
    int best=0, cur=0;
    for(int i=0,j=0;j<n;j++) {
        while(seen.count(a[j])) { seen.erase(a[i]); i++; }
        seen.insert(a[j]);
        best=max(best,j-i+1);
    }
    cout<<best<<"\n";
}
signed main() { int t; cin>>t; while(t--) solve(); }
// 4091000
// 2771
// 2600
// 9736
