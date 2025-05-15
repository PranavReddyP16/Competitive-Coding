#include<bits/stdc++.h>
using namespace std;
class Solution{public:
vector<int> twoSum(vector<int>&nums,int target){
    unordered_map<int,int>m;
    for(int i=0;i<(int)nums.size();i++){
        if(m.count(target-nums[i]))return{m[target-nums[i]],i};
        m[nums[i]]=i;
    }
    return{};
}};
int main(){Solution s;vector<int>v={2,7,11,15};auto r=s.twoSum(v,9);cout<<r[0]<<" "<<r[1];}
