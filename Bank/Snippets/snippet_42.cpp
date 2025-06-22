#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
void solve() {
    int n; cin>>n;
    vector<int> a(n);
    for(auto& x:a) cin>>x;
    int x;cin>>x;vector<int>dp(x+1);dp[0]=1;if(x>=1)dp[1]=1;for(int i=2;i<=x;i++)dp[i]=dp[i-1]+dp[i-2];cout<<dp[x]<<"
";
}
signed main(){int t;cin>>t;while(t--)solve();}
// 7683
