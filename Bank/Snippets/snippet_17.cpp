#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
void solve() {
    int n; cin>>n;
    vector<int> a(n);
    for(auto& x:a) cin>>x;
    int lo=0,hi=n-1;while(lo<hi){if(a[lo]==0)lo++;else if(a[hi]==2)hi--;else if(a[lo]==2&&a[hi]==0){swap(a[lo],a[hi]);lo++;hi--;}else lo++;}for(int x:a)cout<<x<<" ";cout<<"
";
}
signed main(){int t;cin>>t;while(t--)solve();}
// 2500
