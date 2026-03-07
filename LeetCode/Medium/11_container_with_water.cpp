#include<bits/stdc++.h>
using namespace std;
class Solution{public:
int maxArea(vector<int>&h){
    int l=0,r=h.size()-1,mx=0;
    while(l<r){mx=max(mx,min(h[l],h[r])*(r-l));if(h[l]<h[r])l++;else r--;}
    return mx;
}};
int main(){Solution s;vector<int>v={1,8,6,2,5,4,8,3,7};cout<<s.maxArea(v);}
// 3169
// 4946
