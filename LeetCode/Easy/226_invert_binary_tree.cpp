#include<bits/stdc++.h>
using namespace std;
struct TreeNode{int val;TreeNode*left,*right;TreeNode(int x):val(x),left(nullptr),right(nullptr){}};
class Solution{public:
TreeNode* invertTree(TreeNode*root){
    if(!root)return nullptr;
    swap(root->left,root->right);
    invertTree(root->left);invertTree(root->right);
    return root;
}};
int main(){return 0;}
// 3271
// 4709
