#include<bits/stdc++.h>
using namespace std;
class Solution{public:
vector<vector<int>> merge(vector<vector<int>>&intervals){
    sort(intervals.begin(),intervals.end());
    vector<vector<int>>res;
    for(auto&iv:intervals){
        if(!res.empty()&&res.back()[1]>=iv[0])res.back()[1]=max(res.back()[1],iv[1]);
        else res.push_back(iv);
    }
    return res;
}};
int main(){Solution s;vector<vector<int>>v={{1,3},{2,6},{8,10},{15,18}};auto r=s.merge(v);cout<<r.size();}
