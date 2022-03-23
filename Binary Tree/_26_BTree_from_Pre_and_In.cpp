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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> inMap; 

        for(int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }

        TreeNode* root = buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inMap);
        return root;
    }

   TreeNode* buildTree(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, map<int, int> &inMap) {
        
        if(preStart > preEnd || inStart > inEnd) return NULL;

        TreeNode* root = new TreeNode(preorder[preStart]);
        int inRoot = inMap[root->val];      // getting index of root in inorder array
        int numsLeft = inRoot - inStart;

        int left_preStart=preStart+1;
        int left_preEnd =  preStart + numsLeft;
        int left_inStart = inStart;
        int left_inEnd = inRoot-1;

        int right_preStart=preStart+numsLeft+1;
        int right_preEnd =  preEnd;
        int right_inStart = inRoot+1;
        int right_inEnd = inEnd;

        root->left = buildTree(preorder, left_preStart, left_preEnd, inorder, left_inStart,left_inEnd, inMap);
        root->right = buildTree(preorder, right_preStart, right_preEnd, inorder, right_inStart, right_inEnd, inMap);
        
        return root;
    }
};

void preOrderTraversal(TreeNode *root){
    // Root - Left - Right
    if(root==NULL){
        return;
    }
    cout<<root->val<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
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
    vector<int>pre={3,9,20,15,7};
    vector<int>in={9,3,15,20,7};
    Solution obj;
    TreeNode*root= obj.buildTree(pre,in);

    preOrderTraversal(root);
    cout<<endl;
    inOrderTraversal(root);    
    return 0;
}