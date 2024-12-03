#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
void solve() {
    int n; cin>>n;
    vector<int> a(n);
    for(auto& x:a) cin>>x;
    string s;cin>>s;string r;r+=s[0];for(int i=1;i<(int)s.size();i++)if(s[i]!=s[i-1])r+=s[i];cout<<r<<"
";
}
signed main(){int t;cin>>t;while(t--)solve();}
