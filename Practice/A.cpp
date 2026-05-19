#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
void solve() {
    int n; cin>>n;
    vector<int> a(n);
    for(auto& x:a) cin>>x;
    int mx=a[n-1];cout<<mx<<" ";for(int i=n-2;i>=0;i--){if(a[i]>=mx){cout<<a[i]<<" ";mx=a[i];}}cout<<"
";
}
signed main(){int t;cin>>t;while(t--)solve();}
