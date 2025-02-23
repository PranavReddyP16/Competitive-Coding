#include<iostream>
#include<vector>
#include<map>
using namespace std;
#define int long long
void solve() {
    int n; cin>>n;
    vector<int> a(n); for(auto& x:a) cin>>x;
    map<int,int> freq;
    for(int x:a) freq[x]++;
    int mx=0;
    for(auto& [k,v]:freq) mx=max(mx,(int)v);
    cout<<n-mx<<"\n";
}
signed main() { int t; cin>>t; while(t--) solve(); }
// 7348000
