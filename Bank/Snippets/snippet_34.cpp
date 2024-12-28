#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
void solve() {
    int n; cin>>n;
    vector<int> a(n);
    for(auto& x:a) cin>>x;
    long long inv=0;function<void(int,int)>ms=[&](int l,int r){if(r-l<=1)return;int m=(l+r)/2;ms(l,m);ms(m,r);vector<int>t;int i=l,j=m;while(i<m&&j<r){if(a[i]<=a[j])t.push_back(a[i++]);else{t.push_back(a[j++]);inv+=m-i;}}while(i<m)t.push_back(a[i++]);while(j<r)t.push_back(a[j++]);copy(t.begin(),t.end(),a.begin()+l);};ms(0,n);cout<<inv<<"
";
}
signed main(){int t;cin>>t;while(t--)solve();}
