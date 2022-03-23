//https://youtu.be/UmJT3j26t1I
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
    // T=O(nlogn)+O(n) 
    TreeNode*bstfromPre(vector<int>& A){
        vector<int>inorder=A;
        sort(inorder.begin(),inorder.end());
        // We can Construct BT from in and pre discussed before
        return NULL;
    }

    // T= O(N)
    TreeNode* bstFromPreorder(vector<int>& A) {
        int i = 0;
        return build(A, i, INT_MAX);
    }

    TreeNode* build(vector<int>& A, int& i, int bound) {
        if (i == A.size() || A[i] > bound) return NULL;
        TreeNode* root = new TreeNode(A[i++]);
        root->left = build(A, i, root->val);
        root->right = build(A, i, bound);
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
int main(){
    vector<int>pre={8,5,1,7,10,12};
    Solution obj;
    TreeNode*root=obj.bstFromPreorder(pre);
    preOrderTraversal(root);
     
    return 0;
}