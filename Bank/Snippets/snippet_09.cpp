#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
void solve() {
    int n; cin>>n;
    vector<int> a(n);
    for(auto& x:a) cin>>x;
    int x;cin>>x;bool ok=x>1;for(int i=2;i*i<=x;i++)if(x%i==0)ok=false;cout<<(ok?"YES":"NO")<<"
";
}
signed main(){int t;cin>>t;while(t--)solve();}
// 2070
