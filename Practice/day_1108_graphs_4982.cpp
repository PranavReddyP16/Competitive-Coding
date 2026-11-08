#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
void solve() {
    int n; cin>>n;
    vector<int> a(n);
    for(auto& x:a) cin>>x;
    int x;cin>>x;vector<int>dp(x+1,x+1);dp[0]=0;for(int i=1;i<=x;i++)for(int c:a)if(c<=i)dp[i]=min(dp[i],dp[i-c]+1);cout<<(dp[x]>x?-1:dp[x])<<"
";
}
signed main(){int t;cin>>t;while(t--)solve();}
