#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
void solve() {
    int n; cin>>n;
    vector<int> a(n);
    for(auto& x:a) cin>>x;
    map<int,int>f;for(int x:a)f[x]++;vector<pair<int,int>>v;for(auto&[k,c]:f)v.push_back({c,k});sort(v.rbegin(),v.rend());for(auto&[c,k]:v)for(int i=0;i<c;i++)cout<<k<<" ";cout<<"
";
}
signed main(){int t;cin>>t;while(t--)solve();}
