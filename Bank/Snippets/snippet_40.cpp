#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
void solve() {
    int n; cin>>n;
    vector<int> a(n);
    for(auto& x:a) cin>>x;
    int x;cin>>x;int lo=0,hi=n-1;while(lo<=hi){int mid=(lo+hi)/2;if(a[mid]==x){cout<<mid<<"
";return;}if(a[lo]<=a[mid]){if(x>=a[lo]&&x<a[mid])hi=mid-1;else lo=mid+1;}else{if(x>a[mid]&&x<=a[hi])lo=mid+1;else hi=mid-1;}}cout<<-1<<"
";
}
signed main(){int t;cin>>t;while(t--)solve();}
