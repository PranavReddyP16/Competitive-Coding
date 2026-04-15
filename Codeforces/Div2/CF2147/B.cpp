#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
void solve() {
    int n; cin>>n;
    vector<int> a(n);
    for(auto& x:a) cin>>x;
    sort(a.begin(),a.end());int x;cin>>x;cout<<upper_bound(a.begin(),a.end(),x)-lower_bound(a.begin(),a.end(),x)<<"
";
}
signed main(){int t;cin>>t;while(t--)solve();}
