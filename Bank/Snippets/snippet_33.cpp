#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
void solve() {
    int n; cin>>n;
    vector<int> a(n);
    for(auto& x:a) cin>>x;
    sort(a.begin(),a.end());int x;cin>>x;auto it=lower_bound(a.begin(),a.end(),x);int fl=it!=a.begin()?*prev(it):-1;int cl=it!=a.end()?*it:-1;cout<<fl<<" "<<cl<<"
";
}
signed main(){int t;cin>>t;while(t--)solve();}
// 9399
