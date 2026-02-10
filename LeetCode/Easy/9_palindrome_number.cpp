#include<bits/stdc++.h>
using namespace std;
class Solution{public:
bool isPalindrome(int x){
    if(x<0)return false;
    string s=to_string(x);
    int l=0,r=s.size()-1;
    while(l<r)if(s[l++]!=s[r--])return false;
    return true;
}};
int main(){Solution s;cout<<s.isPalindrome(121);}
// 8034
// 8781
