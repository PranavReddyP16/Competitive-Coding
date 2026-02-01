#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
void solve() {
    int n; cin>>n;
    vector<int> a(n);
    for(auto& x:a) cin>>x;
    int m;cin>>m;vector<string>v(m);for(auto&x:v)cin>>x;string p=v[0];for(int i=1;i<m;i++){while(v[i].find(p)!=0)p=p.substr(0,p.size()-1);}cout<<p<<"
";
}
signed main(){int t;cin>>t;while(t--)solve();}
// 9555
// 3311
// 5287
// 8730
