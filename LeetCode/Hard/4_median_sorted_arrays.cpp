#include<bits/stdc++.h>
using namespace std;
class Solution{public:
double findMedianSortedArrays(vector<int>&a,vector<int>&b){
    if(a.size()>b.size())swap(a,b);
    int m=a.size(),n=b.size(),lo=0,hi=m;
    while(lo<=hi){int i=(lo+hi)/2,j=(m+n+1)/2-i;
        int lA=i?a[i-1]:INT_MIN,rA=i<m?a[i]:INT_MAX;
        int lB=j?b[j-1]:INT_MIN,rB=j<n?b[j]:INT_MAX;
        if(lA<=rB&&lB<=rA){if((m+n)%2)return max(lA,lB);return(max(lA,lB)+min(rA,rB))/2.0;}
        if(lA>rB)hi=i-1;else lo=i+1;
    }
    return 0;
}};
int main(){return 0;}
