#include<bits/stdc++.h>
using namespace std;
struct TreeNode{int val;TreeNode*left,*right;TreeNode(int x):val(x),left(nullptr),right(nullptr){}};
class Solution{public:
int ans=INT_MIN;
int dfs(TreeNode*r){if(!r)return 0;int l=max(0,dfs(r->left)),ri=max(0,dfs(r->right));ans=max(ans,l+ri+r->val);return max(l,ri)+r->val;}
int maxPathSum(TreeNode*root){dfs(root);return ans;}
};
int main(){return 0;}
// 4183
