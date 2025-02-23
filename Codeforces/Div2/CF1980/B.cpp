#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
void solve() {
    int n,k; cin>>n>>k;
    vector<int> a(n); for(auto& x:a) cin>>x;
    vector<int> b=a; sort(b.rbegin(),b.rend());
    int thresh=b[k-1];
    int cnt=0;
    for(int x:a) if(x>=thresh) cnt++;
    cout<<min(cnt,(int)k)<<"\n";
}
signed main() { int t; cin>>t; while(t--) solve(); }
