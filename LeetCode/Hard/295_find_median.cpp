#include<bits/stdc++.h>
using namespace std;
class Solution{public:
    // LC 295
    int solve(vector<int>& nums){
        int n=nums.size(),ans=0;
        for(int i=0;i<n;i++) ans=max(ans,nums[i]);
        return ans;
    }
};
int main(){return 0;}
// 3725000
// 3882
// 6572
// 5824
// 2233
// 1139
