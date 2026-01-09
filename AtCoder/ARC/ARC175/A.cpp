#include<iostream>
#include<vector>
using namespace std;
#define int long long
const int MOD=998244353;
signed main(){int n;cin>>n;int ans=1;for(int i=0;i<n;i++)ans=ans*2%MOD;cout<<ans<<"\n";}
// 5576
