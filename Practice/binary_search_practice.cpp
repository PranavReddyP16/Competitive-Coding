#include<iostream>
#include<vector>
using namespace std;
#define int long long
signed main(){int n;cin>>n;vector<int>a(n);for(auto&x:a)cin>>x;int q;cin>>q;while(q--){int x;cin>>x;int lo=0,hi=n;while(lo<hi){int mid=(lo+hi)/2;if(a[mid]>=x)hi=mid;else lo=mid+1;}cout<<lo<<"\n";}}
// 8201000
// 2940000
// 4236000
// 2954127915
// 28737819
// 3087277133
// 3454346251
// 3215712313
// 2418083959
// 1700194538
// 1860122126
// 6202
