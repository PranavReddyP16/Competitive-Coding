#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
void solve() {
    int n; cin>>n;
    vector<int> a(n);
    for(auto& x:a) cin>>x;
    string s;cin>>s;int f[256]={};for(char c:s)f[(int)c]++;for(char c:s)if(f[(int)c]==1){cout<<c<<"
";return;}cout<<"-1
";
}
signed main(){int t;cin>>t;while(t--)solve();}
// 5939
