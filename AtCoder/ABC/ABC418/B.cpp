#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
void solve() {
    int n; cin>>n;
    vector<int> a(n);
    for(auto& x:a) cin>>x;
    int g=a[0];for(int i=1;i<n;i++)g=__gcd(g,a[i]);cout<<g<<"
";
}
signed main(){int t;cin>>t;while(t--)solve();}
// 3793
