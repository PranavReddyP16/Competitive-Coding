#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
signed main(){int n;cin>>n;vector<pair<int,int>>iv(n);for(auto&[a,b]:iv)cin>>a>>b;sort(iv.begin(),iv.end(),[](auto&a,auto&b){return a.second<b.second;});int cnt=0,last=-1e18;for(auto&[a,b]:iv)if(a>=last){cnt++;last=b;}cout<<cnt<<"\n";}
// 7052000
// 1853000
// 8199000
// 5357000
// 1940022204
// 805277075
// 2357339064
// 1712160661
// 1700996383
// 2553589244
// 34362535
// 2853763658
// 7967
