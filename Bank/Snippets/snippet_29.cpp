#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
void solve() {
    int n; cin>>n;
    vector<int> a(n);
    for(auto& x:a) cin>>x;
    string s;cin>>s;int len=s.size();vector<vector<int>>dp(len,vector<int>(len,0));for(int l=2;l<=len;l++)for(int i=0;i<=len-l;i++){int j=i+l-1;dp[i][j]=s[i]==s[j]?dp[i+1][j-1]:min(dp[i+1][j],dp[i][j-1])+1;}cout<<dp[0][len-1]<<"
";
}
signed main(){int t;cin>>t;while(t--)solve();}
