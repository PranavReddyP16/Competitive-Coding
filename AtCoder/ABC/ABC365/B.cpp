#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
signed main(){int n;cin>>n;vector<int>a(n);for(auto&x:a)cin>>x;sort(a.begin(),a.end());for(int x:a)cout<<x<<" ";}
// 5680
