#include<iostream>
using namespace std;
void solve() {
    int h,m; cin>>h>>m;
    int total=h*60+m;
    cout<<total/60<<" "<<total%60<<"\n";
}
signed main() { int t; cin>>t; while(t--) solve(); }
// 6222
