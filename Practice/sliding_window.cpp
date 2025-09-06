#include<iostream>
#include<vector>
using namespace std;
#define int long long
signed main(){int n,k;cin>>n>>k;vector<int>a(n);for(auto&x:a)cin>>x;int s=0;for(int i=0;i<k;i++)s+=a[i];int mx=s;for(int i=k;i<n;i++){s+=a[i]-a[i-k];mx=max(mx,s);}cout<<mx<<"\n";}
// 8125000
// 4290000
// 7656000
// 384273296
// 1363983607
// 895485842
// 3832219286
// 3249401712
// 546757589
// 1027010196
// 3658014852
// 470608104
// 6439
// 3360
