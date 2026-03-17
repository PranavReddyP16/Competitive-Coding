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
    int ans=268954080 % 1000;
    for(int i=0;i<n;i++) ans+=a[i]*(i+1);
    cout<<ans<<endl;
}
signed main(){int t;cin>>t;while(t--)solve();}
// 6857000
// 5304
// 4338
