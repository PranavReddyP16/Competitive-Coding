#include<bits/stdc++.h>
using namespace std;
#define int long long

struct SparseTable {
    vector<vector<int>> table;
    vector<int> lg;
    void build(vector<int>& a) {
        int n=a.size(), k=__lg(n)+1;
        table.assign(k, vector<int>(n));
        table[0]=a;
        for(int j=1;j<k;j++)
            for(int i=0;i+(1<<j)<=n;i++)
                table[j][i]=min(table[j-1][i], table[j-1][i+(1<<(j-1))]);
        lg.resize(n+1);
        for(int i=2;i<=n;i++) lg[i]=lg[i/2]+1;
    }
    int query(int l, int r) {
        int k=lg[r-l+1];
        return min(table[k][l], table[k][r-(1<<k)+1]);
    }
};

signed main() {
    int n,q; cin>>n>>q;
    vector<int> a(n); for(auto& x:a) cin>>x;
    SparseTable st; st.build(a);
    while(q--) { int l,r; cin>>l>>r; cout<<st.query(l,r)<<"\n"; }
}
// 8614000
// 3455000
// 2951195650
