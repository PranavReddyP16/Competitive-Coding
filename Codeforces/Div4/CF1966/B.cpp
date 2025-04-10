#include<iostream>
#include<vector>
using namespace std;
#define int long long
void solve(){int n;cin>>n;vector<int>a(n);for(auto&x:a)cin>>x;for(int i=0;i<n-1;i++)if(a[i]>a[i+1]&&(a[i]-a[i+1])%2!=0){cout<<"NO\n";return;}cout<<"YES\n";}
signed main(){int t;cin>>t;while(t--)solve();}
// 8149000
