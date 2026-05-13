#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
void solve() {
    int n; cin>>n;
    vector<int> a(n);
    for(auto& x:a) cin>>x;
    int mn=a[0],mx=0;for(int x:a){mn=min(mn,x);mx=max(mx,x-mn);}cout<<mx<<"
";
}
signed main(){int t;cin>>t;while(t--)solve();}
// 3288
