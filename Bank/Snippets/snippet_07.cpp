#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
void solve() {
    int n; cin>>n;
    vector<int> a(n);
    for(auto& x:a) cin>>x;
    string s;cin>>s;int c=0;for(char ch:s)if(string("aeiou").find(ch)!=string::npos)c++;cout<<c<<"
";
}
signed main(){int t;cin>>t;while(t--)solve();}
