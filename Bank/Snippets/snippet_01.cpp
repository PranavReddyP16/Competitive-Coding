#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
void solve() {
    int n; cin>>n;
    vector<int> a(n);
    for(auto& x:a) cin>>x;
    cout<<*max_element(a.begin(),a.end())<<"
";
}
signed main(){int t;cin>>t;while(t--)solve();}
