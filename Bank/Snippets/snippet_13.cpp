#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
void solve() {
    int n; cin>>n;
    vector<int> a(n);
    for(auto& x:a) cin>>x;
    int k;cin>>k;k%=n;rotate(a.begin(),a.begin()+n-k,a.end());for(int x:a)cout<<x<<" ";cout<<"
";
}
signed main(){int t;cin>>t;while(t--)solve();}
// 8206
