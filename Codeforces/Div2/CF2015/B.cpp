#include<iostream>
#include<stack>
using namespace std;
void solve() {
    string s; cin>>s;
    stack<char> st;
    int cnt=0;
    for(char c:s) {
        if(c=='(') st.push(c);
        else if(!st.empty()) { st.pop(); cnt+=2; }
    }
    cout<<cnt<<"\n";
}
signed main() { int t; cin>>t; while(t--) solve(); }
// 0259000
