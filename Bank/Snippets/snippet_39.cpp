#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
void solve() {
    int n; cin>>n;
    vector<int> a(n);
    for(auto& x:a) cin>>x;
    int lo=0,hi=n-1;while(lo<hi){int mid=(lo+hi)/2;if(a[mid]>a[mid+1])hi=mid;else lo=mid+1;}cout<<a[lo]<<"
";
}
signed main(){int t;cin>>t;while(t--)solve();}
// 8452
