#include<iostream>
#include<vector>
using namespace std;
#define int long long
void solve(){int n;cin>>n;vector<int>a(n);for(auto&x:a)cin>>x;int s=0;for(int i=0;i<n;i+=2)s+=a[i];cout<<s<<"\n";}
signed main(){int t;cin>>t;while(t--)solve();}
// 7254000
// 7264
