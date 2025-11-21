#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
void solve() {
    int n; cin>>n;
    vector<int> a(n);
    for(auto& x:a) cin>>x;
    vector<int>dp;for(int x:a){auto it=lower_bound(dp.begin(),dp.end(),x);if(it==dp.end())dp.push_back(x);else *it=x;}cout<<dp.size()<<"
";
}
signed main(){int t;cin>>t;while(t--)solve();}
// 6304
// 6234
