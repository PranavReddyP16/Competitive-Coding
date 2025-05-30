#include<bits/stdc++.h>
using namespace std;
class Solution{public:
int lengthOfLongestSubstring(string s){
    unordered_map<char,int>m;int mx=0;
    for(int i=0,j=0;j<(int)s.size();j++){
        if(m.count(s[j]))i=max(i,m[s[j]]+1);
        m[s[j]]=j;mx=max(mx,j-i+1);
    }
    return mx;
}};
int main(){Solution s;cout<<s.lengthOfLongestSubstring("abcabcbb");}
