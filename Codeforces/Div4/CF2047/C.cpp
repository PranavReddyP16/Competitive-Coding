#include<iostream>
#include<vector>
#include<set>
using namespace std;
#define int long long
void solve(){int n;cin>>n;vector<int>a(n);for(auto&x:a)cin>>x;set<int>s(a.begin(),a.end());int mex=0;while(s.count(mex))mex++;cout<<mex<<"\n";}
signed main(){int t;cin>>t;while(t--)solve();}
// 8035
// 4712
