#include<bits/stdc++.h>
using namespace std;
class Solution{public:
int trap(vector<int>&h){
    int l=0,r=h.size()-1,lmax=0,rmax=0,ans=0;
    while(l<r){if(h[l]<h[r]){lmax=max(lmax,h[l]);ans+=lmax-h[l];l++;}else{rmax=max(rmax,h[r]);ans+=rmax-h[r];r--;}}
    return ans;
}};
int main(){Solution s;vector<int>v={0,1,0,2,1,0,1,3,2,1,2,1};cout<<s.trap(v);}
// cleanup for github
// 8940
// 5283
