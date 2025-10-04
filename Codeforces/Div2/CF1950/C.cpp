#include<iostream>
#include<vector>
#include<set>
using namespace std;
#define int long long
void solve() {
    int n; cin>>n;
    vector<int> a(n); for(auto& x:a) cin>>x;
    set<int> s;
    for(int i=0;i<=n;i++) s.insert(i);
    for(int x:a) s.erase(x);
    cout<<*s.begin()<<"\n";
}
signed main() { int t; cin>>t; while(t--) solve(); }
// updated
// 2741
// 5063
