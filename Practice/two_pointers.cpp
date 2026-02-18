#include<iostream>
#include<vector>
using namespace std;
#define int long long
signed main(){int n,k;cin>>n>>k;vector<int>a(n);for(auto&x:a)cin>>x;int best=0,s=0;for(int i=0,j=0;j<n;j++){s+=a[j];while(s>k){s-=a[i];i++;}best=max(best,j-i+1);}cout<<best<<"\n";}
// 9749000
// 2072000
// 3408000
// 312870712
// 2764330426
// 1730457156
// 513037292
// 3214832616
// 4215214191
// 4033375844
// 805742312
// 2593355239
// 1402419798
// 8502
