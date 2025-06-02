#include<iostream>
#include<vector>
using namespace std;
#define int long long
signed main(){int n,W;cin>>n>>W;vector<int>w(n),v(n);for(int i=0;i<n;i++)cin>>w[i]>>v[i];vector<int>dp(W+1,0);for(int i=0;i<n;i++)for(int j=W;j>=w[i];j--)dp[j]=max(dp[j],dp[j-w[i]]+v[i]);cout<<dp[W]<<"\n";}
// added edge case
// 9189000
// 6877000
// 6057000
// 9519000
// 4433000
// 5626000
// 435415577
// 3376895289
// 1474377233
// 3203840526
// 2826925821
// 1203116269
// 1742367335
// 1019881739
// 3647513863
// 1675439016
// 547700998
