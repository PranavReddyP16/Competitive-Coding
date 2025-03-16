#include<iostream>
using namespace std;
void solve(){string s;cin>>s;int n=s.size();int ans=0;for(int i=0;i<n-1;i++)if(s[i]!=s[i+1])ans++;cout<<ans<<"\n";}
signed main(){int t;cin>>t;while(t--)solve();}
// 7540000
// 1132
