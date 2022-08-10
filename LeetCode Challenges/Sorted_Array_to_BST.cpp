//https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
    TreeNode * solve(vector<int>& nums,int start,int end){
        if(start>end){return nullptr;}
        int mid=start+(end-start)/2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = solve(nums,start,mid-1);
        node->right=solve(nums,mid+1,end);
        return node;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solve(nums,0,nums.size()-1);
    }
};
void inOrderTraversal(TreeNode *root){
    // Left- Root - Right
    if(root==NULL){
        return;
    }
    inOrderTraversal(root->left);
    cout<<root->val<<" ";
    inOrderTraversal(root->right);
}
int main(){
    vector<int>nums={-10,-3,0,5,9};
    Solution obj;
    TreeNode* root =obj.sortedArrayToBST(nums);
    inOrderTraversal(root);
    return 0;
}