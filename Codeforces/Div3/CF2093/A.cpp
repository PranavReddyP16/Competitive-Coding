#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
void solve(){int n;cin>>n;vector<int>a(n);for(auto&x:a)cin>>x;
sort(a.begin(),a.end());int r=0;for(int i=0;i<n;i++)r+=a[i]*(i+1);
cout<<r<<endl;}
signed main(){int t;cin>>t;while(t--)solve();}
// 2936800073
