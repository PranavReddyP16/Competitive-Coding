#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
void solve() {
    int n; cin>>n;
    vector<int> a(n);
    for(auto& x:a) cin>>x;
    a.erase(unique(a.begin(),a.end()),a.end());for(int x:a)cout<<x<<" ";cout<<"
";
}
signed main(){int t;cin>>t;while(t--)solve();}
