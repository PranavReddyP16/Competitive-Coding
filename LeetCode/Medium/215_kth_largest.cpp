#include<bits/stdc++.h>
using namespace std;
class Solution{public:
    // LC 215
    int solve(vector<int>& nums){
        int n=nums.size(),ans=0;
        for(int i=0;i<n;i++) ans=max(ans,nums[i]);
        return ans;
    }
};
int main(){return 0;}
// 6346000
