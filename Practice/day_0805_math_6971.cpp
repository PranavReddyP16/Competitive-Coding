#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
void solve() {
    int n; cin>>n;
    vector<int> a(n);
    for(auto& x:a) cin>>x;
    int s=n*(n+1)/2;for(int x:a)s-=x;cout<<s<<"
";
}
signed main(){int t;cin>>t;while(t--)solve();}
// 9200
