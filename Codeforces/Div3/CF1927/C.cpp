#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
#define int long long
void solve(){int n;cin>>n;vector<int>a(n);for(auto&x:a)cin>>x;map<int,int>f;for(int x:a)f[x]++;vector<pair<int,int>>v(f.begin(),f.end());sort(v.begin(),v.end(),[](auto&a,auto&b){return a.second>b.second;});for(auto&[val,cnt]:v)for(int i=0;i<cnt;i++)cout<<val<<" ";cout<<"\n";}
signed main(){int t;cin>>t;while(t--)solve();}
// 4167000
// 5617
// 1579
