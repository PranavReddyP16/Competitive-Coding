#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
void solve() {
    int n; cin>>n;
    vector<int> a(n);
    for(auto& x:a) cin>>x;
    int s=0;for(int x:a)if(x%2==0)s+=x;cout<<s<<"
";
}
signed main(){int t;cin>>t;while(t--)solve();}
// 9665
// 3446
