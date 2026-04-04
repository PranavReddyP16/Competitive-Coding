#include<bits/stdc++.h>
using namespace std;
#define int long long

// Find first index where check(mid) is true
int first_true(int lo, int hi, auto check) {
    while(lo<hi) {
        int mid=lo+(hi-lo)/2;
        if(check(mid)) hi=mid;
        else lo=mid+1;
    }
    return lo;
}

// Find last index where check(mid) is true
int last_true(int lo, int hi, auto check) {
    while(lo<hi) {
        int mid=lo+(hi-lo+1)/2;
        if(check(mid)) lo=mid;
        else hi=mid-1;
    }
    return lo;
}

signed main() {
    int n; cin>>n;
    vector<int> a(n);
    for(auto& x:a) cin>>x;
    sort(a.begin(),a.end());
    int q; cin>>q;
    while(q--) {
        int x; cin>>x;
        int pos=first_true(0,n,[&](int mid){ return a[mid]>=x; });
        cout<<pos<<"\n";
    }
}
// 5334000
// 6709000
// 2749710637
// Optimization: use __builtin_clz for faster operations
