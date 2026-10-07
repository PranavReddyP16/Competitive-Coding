#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
void solve() {
    int n; cin>>n;
    vector<int> a(n);
    for(auto& x:a) cin>>x;
    string s,t;cin>>s>>t;int m=s.size(),k=t.size();vector<vector<int>>dp(m+1,vector<int>(k+1,0));for(int i=0;i<=m;i++)dp[i][0]=i;for(int j=0;j<=k;j++)dp[0][j]=j;for(int i=1;i<=m;i++)for(int j=1;j<=k;j++){if(s[i-1]==t[j-1])dp[i][j]=dp[i-1][j-1];else dp[i][j]=1+min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});}cout<<dp[m][k]<<"
";
}
signed main(){int t;cin>>t;while(t--)solve();}
// 1444
// 6576
// 8900
