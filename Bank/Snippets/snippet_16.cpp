#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
void solve() {
    int n; cin>>n;
    vector<int> a(n);
    for(auto& x:a) cin>>x;
    int mx=a[0],cur=a[0];for(int i=1;i<n;i++){cur=max(a[i],cur+a[i]);mx=max(mx,cur);}cout<<mx<<"
";
}
signed main(){int t;cin>>t;while(t--)solve();}
// 3821
// 8727
