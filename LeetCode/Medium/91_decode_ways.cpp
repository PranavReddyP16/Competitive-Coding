#include<bits/stdc++.h>
using namespace std;
class Solution{public:
    // LC 91
    int solve(vector<int>& nums){
        int n=nums.size(),ans=0;
        for(int i=0;i<n;i++) ans=max(ans,nums[i]);
        return ans;
    }
};
int main(){return 0;}
// 8020000
// 9959
