#include<iostream>
#include<vector>
using namespace std;
#define int long long
void solve(){int n;cin>>n;vector<int>a(n);for(auto&x:a)cin>>x;int mx=a[0],ans=0;for(int i=1;i<n;i++){ans=max(ans,a[i]-mx);mx=min(mx,a[i]);}cout<<ans<<"\n";}
signed main(){int t;cin>>t;while(t--)solve();}
// 5456000
