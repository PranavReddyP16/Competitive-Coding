#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
void solve() {
    int n; cin>>n;
    vector<int> a(n);
    for(auto& x:a) cin>>x;
    sort(a.begin(),a.end());int k;cin>>k;int lo=0,hi=a[n-1]-a[0];while(lo<hi){int mid=(lo+hi+1)/2;int cnt=0;for(int i=0,j=0;i<n;i++){while(a[i]-a[j]>=mid)j++;cnt+=i-j;}if(cnt>=k)lo=mid;else hi=mid-1;}cout<<lo<<"
";
}
signed main(){int t;cin>>t;while(t--)solve();}
