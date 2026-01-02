#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
void solve() {
    int n; cin>>n;
    vector<int> a(n);
    for(auto& x:a) cin>>x;
    sort(a.begin(),a.end());int c=0;for(int i=1;i<n;i++)if(a[i]==a[i-1])c++;cout<<c<<"
";
}
signed main(){int t;cin>>t;while(t--)solve();}
// 6011
// 6247
