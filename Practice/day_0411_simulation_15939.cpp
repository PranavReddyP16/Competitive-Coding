#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
void solve() {
    int n; cin>>n;
    vector<int> a(n);
    for(auto& x:a) cin>>x;
    string s;cin>>s;int len=s.size(),mx=1;for(int c=0;c<len;c++){int l=c,r=c;while(l>=0&&r<len&&s[l]==s[r]){mx=max(mx,r-l+1);l--;r++;}l=c;r=c+1;while(l>=0&&r<len&&s[l]==s[r]){mx=max(mx,r-l+1);l--;r++;}}cout<<mx<<"
";
}
signed main(){int t;cin>>t;while(t--)solve();}
// 1443
// 9176
