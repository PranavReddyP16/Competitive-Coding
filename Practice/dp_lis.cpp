#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
signed main(){int n;cin>>n;vector<int>a(n);for(auto&x:a)cin>>x;vector<int>dp;for(int x:a){auto it=lower_bound(dp.begin(),dp.end(),x);if(it==dp.end())dp.push_back(x);else *it=x;}cout<<dp.size()<<"\n";}
// practice round
// 5983000
// 8238000
// 0425000
// 5124000
// 1742794155
// 2700241981
// 948929305
// 3681250667
// 1939521850
// 64870073
// 907971555
// 4010469299
// 3922809352
// 462631287
// 6080
