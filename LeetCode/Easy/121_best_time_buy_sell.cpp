#include<bits/stdc++.h>
using namespace std;
class Solution{public:
int maxProfit(vector<int>&prices){
    int mn=prices[0],mx=0;
    for(int p:prices){mn=min(mn,p);mx=max(mx,p-mn);}
    return mx;
}};
int main(){Solution s;vector<int>v={7,1,5,3,6,4};cout<<s.maxProfit(v);}
// 2505
