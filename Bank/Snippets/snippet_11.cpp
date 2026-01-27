#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
void solve() {
    int n; cin>>n;
    vector<int> a(n);
    for(auto& x:a) cin>>x;
    reverse(a.begin(),a.end());for(int x:a)cout<<x<<" ";cout<<"
";
}
signed main(){int t;cin>>t;while(t--)solve();}
// 3974
// 9043
// 8575
// 9526
// 2045
