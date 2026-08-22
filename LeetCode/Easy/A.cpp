#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
void solve() {
    int n; cin>>n;
    vector<int> a(n);
    for(auto& x:a) cin>>x;
    int k;cin>>k;sort(a.begin(),a.end());cout<<a[k-1]<<"
";
}
signed main(){int t;cin>>t;while(t--)solve();}
