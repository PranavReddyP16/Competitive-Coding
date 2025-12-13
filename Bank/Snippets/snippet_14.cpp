#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
void solve() {
    int n; cin>>n;
    vector<int> a(n);
    for(auto& x:a) cin>>x;
    int m;cin>>m;vector<int>b(m);for(auto&x:b)cin>>x;vector<int>c;merge(a.begin(),a.end(),b.begin(),b.end(),back_inserter(c));for(int x:c)cout<<x<<" ";cout<<"
";
}
signed main(){int t;cin>>t;while(t--)solve();}
// 1224
