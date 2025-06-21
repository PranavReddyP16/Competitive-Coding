#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
void solve() {
    int n; cin>>n;
    vector<int> a(n);
    for(auto& x:a) cin>>x;
    string s;cin>>s;int f[26]={};for(char c:s)f[c- ' a ' ]++;for(int i=0;i<26;i++)if(f[i])cout<<(char)( ' a ' +i)<<":"<<f[i]<<" ";cout<<"
";
}
signed main(){int t;cin>>t;while(t--)solve();}
// 4419
