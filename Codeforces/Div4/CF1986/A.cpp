#include<iostream>
using namespace std;
void solve(){string s;cin>>s;bool has_upper=false,has_lower=false;for(char c:s){if(c>='A'&&c<='Z')has_upper=true;if(c>='a'&&c<='z')has_lower=true;}cout<<(has_upper&&has_lower?"YES":"NO")<<"\n";}
signed main(){int t;cin>>t;while(t--)solve();}
