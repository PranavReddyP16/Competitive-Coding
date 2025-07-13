#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
void solve() {
    int n; cin>>n;
    vector<int> a(n);
    for(auto& x:a) cin>>x;
    int x;cin>>x;int a_=0,b_=1;for(int i=2;i<=x;i++){int c=a_+b_;a_=b_;b_=c;}cout<<b_<<"
";
}
signed main(){int t;cin>>t;while(t--)solve();}
// 3172
