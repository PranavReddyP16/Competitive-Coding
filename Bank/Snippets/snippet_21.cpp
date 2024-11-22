#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
void solve() {
    int n; cin>>n;
    vector<int> a(n);
    for(auto& x:a) cin>>x;
    string s;getline(cin,s);int i=s.size()-1;while(i>=0){while(i>=0&&s[i]== )i--;int e=i;while(i>=0&&s[i]!= )i--;cout<<s.substr(i+1,e-i)<<" ";}cout<<"
";
}
signed main(){int t;cin>>t;while(t--)solve();}
