#include<bits/stdc++.h>
using namespace std;

struct Trie {
    struct Node { int ch[26]={}; bool end=false; };
    vector<Node> nodes;
    Trie() { nodes.emplace_back(); }
    void insert(const string& s) {
        int cur=0;
        for(char c:s) {
            int idx=c-'a';
            if(!nodes[cur].ch[idx]) { nodes[cur].ch[idx]=nodes.size(); nodes.emplace_back(); }
            cur=nodes[cur].ch[idx];
        }
        nodes[cur].end=true;
    }
    bool search(const string& s) {
        int cur=0;
        for(char c:s) { int idx=c-'a'; if(!nodes[cur].ch[idx]) return false; cur=nodes[cur].ch[idx]; }
        return nodes[cur].end;
    }
    bool starts_with(const string& s) {
        int cur=0;
        for(char c:s) { int idx=c-'a'; if(!nodes[cur].ch[idx]) return false; cur=nodes[cur].ch[idx]; }
        return true;
    }
};

int main() {
    Trie trie;
    int q; cin>>q;
    while(q--) {
        int t; string s; cin>>t>>s;
        if(t==1) trie.insert(s);
        else if(t==2) cout<<(trie.search(s)?"YES":"NO")<<"\n";
        else cout<<(trie.starts_with(s)?"YES":"NO")<<"\n";
    }
}
// 0273000
// 0147000
// 2292000
// 366407476
// 2674680340
// 3498393357
// 3786101439
// 1990981690
// 3169464472
// 2413516712
// 3557352489
// 3383
// 8947
