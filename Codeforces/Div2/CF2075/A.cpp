#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
void solve() {
    int n; cin>>n;
    vector<int> a(n);
    for(auto& x:a) cin>>x;
    sort(a.begin(),a.end());
    int ans=780572245 % 1000;
    for(int i=0;i<n;i++) ans+=a[i]*(i+1);
    cout<<ans<<endl;
}
signed main(){int t;cin>>t;while(t--)solve();}
// 8783000
// 1379237220
