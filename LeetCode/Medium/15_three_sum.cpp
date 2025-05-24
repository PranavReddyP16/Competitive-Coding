#include<bits/stdc++.h>
using namespace std;
class Solution{public:
vector<vector<int>> threeSum(vector<int>&nums){
    sort(nums.begin(),nums.end());
    vector<vector<int>>res;int n=nums.size();
    for(int i=0;i<n-2;i++){
        if(i&&nums[i]==nums[i-1])continue;
        int l=i+1,r=n-1;
        while(l<r){int s=nums[i]+nums[l]+nums[r];
            if(s<0)l++;else if(s>0)r--;
            else{res.push_back({nums[i],nums[l],nums[r]});while(l<r&&nums[l]==nums[l+1])l++;while(l<r&&nums[r]==nums[r-1])r--;l++;r--;}
        }
    }
    return res;
}};
int main(){Solution s;vector<int>v={-1,0,1,2,-1,-4};auto r=s.threeSum(v);cout<<r.size();}
