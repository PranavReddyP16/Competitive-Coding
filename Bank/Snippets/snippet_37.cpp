#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
void solve() {
    int n; cin>>n;
    vector<int> a(n);
    for(auto& x:a) cin>>x;
    vector<int>b(n);for(auto&x:b)cin>>x;vector<int>ev;for(int i=0;i<n;i++){ev.push_back(a[i]);ev.push_back(b[i]);}sort(ev.begin(),ev.end());int cur=0,mx=0;for(int i=0;i<n;i++){cur++;mx=max(mx,cur);}cout<<mx<<"
";
}
signed main(){int t;cin>>t;while(t--)solve();}
// 9976
