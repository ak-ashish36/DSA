//https://leetcode.com/problems/validate-binary-search-tree/
//https://youtu.be/f-sj7I5oXEI
#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode*left,*right;
    TreeNode(int val=0){
        this->val=val;
        left=right=NULL;
    }
}; 
class Solution {
public:
    TreeNode* pre = NULL;
    bool isValidBST(TreeNode* root) {
        if (root == NULL) return true;
        bool left = isValidBST(root->left);
        if (pre != NULL && pre->val >= root->val) return false;
        pre = root;
        bool right = isValidBST(root->right);
        return left && right;
    }

    // 2nd Way
    bool isValidBST2(TreeNode* root) {
        return isValidBST2(root, LONG_MIN, LONG_MAX);
    }
    
    bool isValidBST2(TreeNode* root, long minVal, long maxVal) {
        if (root == NULL) return true;
        if (root->val >= maxVal || root->val <= minVal) return false;
        return isValidBST2(root->left, minVal, root->val) && isValidBST2(root->right, root->val, maxVal);
    }
};
   

int main(){
    TreeNode * root = new TreeNode(1);

    root->left=new TreeNode(1);   
    root->right=new TreeNode(4); 

    root->left->left=new TreeNode(4);            
    root->left->right=new TreeNode(7);
    root->right->left=new TreeNode(3);            
    root->right->right=new TreeNode(6);
    Solution obj;

    cout<<obj.isValidBST(root);
    return 0;
}