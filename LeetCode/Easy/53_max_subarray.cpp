#include<bits/stdc++.h>
using namespace std;
class Solution{public:
int maxSubArray(vector<int>&nums){
    int mx=nums[0],cur=nums[0];
    for(int i=1;i<(int)nums.size();i++){cur=max(nums[i],cur+nums[i]);mx=max(mx,cur);}
    return mx;
}};
int main(){Solution s;vector<int>v={-2,1,-3,4,-1,2,1,-5,4};cout<<s.maxSubArray(v);}
// 9872
// 7625
// 5979
