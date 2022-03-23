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
    TreeNode* buildTree(vector<int>& postorder, vector<int>& inorder) {
        map<int, int> inMap; 

        for(int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }

        TreeNode* root = buildTree(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1, inMap);
        return root;
    }

   TreeNode* buildTree(vector<int>& postorder, int postStart, int postEnd, vector<int>& inorder, int inStart, int inEnd, map<int, int> &inMap) {
        
        if(postStart > postEnd || inStart > inEnd) return NULL;

        TreeNode* root = new TreeNode(postorder[postEnd]);
        int inRoot = inMap[postorder[postEnd]];      // getting index of root in inorder array
        int numsLeft = inRoot - inStart;

        int left_postStart=postStart;
        int left_postEnd =  postStart + numsLeft-1;
        int left_inStart = inStart;
        int left_inEnd = inRoot-1;

        int right_postStart=postStart+numsLeft;
        int right_postEnd =  postEnd-1;
        int right_inStart = inRoot+1;
        int right_inEnd = inEnd;

        root->left = buildTree(postorder, left_postStart, left_postEnd, inorder, left_inStart,left_inEnd, inMap);
        root->right = buildTree(postorder, right_postStart, right_postEnd, inorder, right_inStart, right_inEnd, inMap);
        return root;
    }
};

void postOrderTraversal(TreeNode *root){
    // Left - Right -Root
    if(root==NULL){
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->val<<" ";
}
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
    vector<int>post={9,15,7,20,3};
    vector<int>in={9,3,15,20,7};
    Solution obj;
    TreeNode*root= obj.buildTree(post,in);

    postOrderTraversal(root);
    cout<<endl;
    inOrderTraversal(root);    
    return 0;
}