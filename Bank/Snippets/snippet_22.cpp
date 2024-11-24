#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
void solve() {
    int n; cin>>n;
    vector<int> a(n);
    for(auto& x:a) cin>>x;
    string s,t;cin>>s>>t;sort(s.begin(),s.end());sort(t.begin(),t.end());cout<<(s==t?"YES":"NO")<<"
";
}
signed main(){int t;cin>>t;while(t--)solve();}
