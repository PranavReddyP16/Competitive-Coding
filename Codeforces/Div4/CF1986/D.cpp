#include<iostream>
#include<vector>
using namespace std;
#define int long long
void solve(){int n;cin>>n;vector<int>a(n);for(auto&x:a)cin>>x;vector<int>pre(n+1,0);for(int i=0;i<n;i++)pre[i+1]=pre[i]+a[i];int ans=0;for(int i=0;i<n;i++)for(int j=i;j<n;j++)ans+=pre[j+1]-pre[i];cout<<ans<<"\n";}
signed main(){int t;cin>>t;while(t--)solve();}
// 3397
// 8116
// 4143
// 9908
