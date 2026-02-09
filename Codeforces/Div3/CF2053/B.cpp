#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
void solve(){int n;cin>>n;vector<int>a(n);for(auto&x:a)cin>>x;sort(a.begin(),a.end());cout<<a.back()-a[0]<<"\n";}
signed main(){int t;cin>>t;while(t--)solve();}
// 3622000
// 8379
