#include<iostream>
#include<algorithm>
using namespace std;
void solve(){string s;cin>>s;string t=s;reverse(t.begin(),t.end());cout<<(s==t?"YES":"NO")<<"\n";}
signed main(){int t;cin>>t;while(t--)solve();}
// 1633000
// 5622
// 6339
