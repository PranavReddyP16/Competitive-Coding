#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
void solve() {
    int n; cin>>n;
    vector<int> a(n);
    for(auto& x:a) cin>>x;
    int total=0;for(int x:a)total+=x;int left=0;for(int i=0;i<n;i++){if(left==total-left-a[i]){cout<<i<<"
";return;}left+=a[i];}cout<<-1<<"
";
}
signed main(){int t;cin>>t;while(t--)solve();}
