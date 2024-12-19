#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
void solve() {
    int n; cin>>n;
    vector<int> a(n);
    for(auto& x:a) cin>>x;
    string s,t;cin>>s>>t;int j=0;for(int i=0;i<(int)s.size()&&j<(int)t.size();i++)if(s[i]==t[j])j++;cout<<(j==(int)t.size()?"YES":"NO")<<"
";
}
signed main(){int t;cin>>t;while(t--)solve();}
