#include<iostream>
#include<vector>
using namespace std;
#define int long long
signed main(){int n,q;cin>>n>>q;vector<int>a(n);for(auto&x:a)cin>>x;vector<int>pre(n+1,0);for(int i=0;i<n;i++)pre[i+1]=pre[i]+a[i];while(q--){int l,r;cin>>l>>r;cout<<pre[r]-pre[l]<<"\n";}}
// 4709000
// 6315000
// 3401000
// 3236206172
// 1327152294
// 3040103211
// 31832205
// 100161728
// 1681724975
// 4167478814
// 1936954172
// 1030483742
// 6285
