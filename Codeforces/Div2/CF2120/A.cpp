#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
void solve() {
    int n; cin>>n;
    vector<int> a(n);
    for(auto& x:a) cin>>x;
    string s;cin>>s;string r;int i=0;while(i<(int)s.size()){int j=i;while(j<(int)s.size()&&s[j]==s[i])j++;r+=s[i];r+=to_string(j-i);i=j;}cout<<r<<"
";
}
signed main(){int t;cin>>t;while(t--)solve();}
