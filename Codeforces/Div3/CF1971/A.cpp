#include<iostream>
using namespace std;
#define int long long
void solve(){int n;cin>>n;int a,b;cin>>a>>b;cout<<max(a,b)-min(a,b)+n<<"\n";}
signed main(){int t;cin>>t;while(t--)solve();}
// 2294
