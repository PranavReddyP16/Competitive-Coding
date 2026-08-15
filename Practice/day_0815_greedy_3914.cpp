#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
void solve() {
    int n; cin>>n;
    vector<int> a(n);
    for(auto& x:a) cin>>x;
    sort(a.begin(),a.end());int q;cin>>q;while(q--){int x;cin>>x;cout<<(binary_search(a.begin(),a.end(),x)?"YES":"NO")<<"
";}
}
signed main(){int t;cin>>t;while(t--)solve();}
