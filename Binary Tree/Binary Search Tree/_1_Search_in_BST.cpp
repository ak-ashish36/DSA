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
TreeNode* searchBST(TreeNode* root, int val) {
   if(root == NULL) return NULL;
   if(val == root->val){
       return root;
   }
   else if(val < root->val){
       return searchBST(root->left, val);
   }else{
       return searchBST(root->right, val);
   }
}
TreeNode* searchBST_Iter(TreeNode* root, int val) {
    while(root != NULL && root->val != val){
        root = val<root->val? root->left:root->right;
    }
    return root;
}
int main(){
 TreeNode * root = new TreeNode(8);

    root->left=new TreeNode(5);   
    root->right=new TreeNode(12); 

    root->left->left=new TreeNode(4);            
    root->left->right=new TreeNode(7);
    root->right->left=new TreeNode(10);            
    root->right->right=new TreeNode(14);

    TreeNode *found =searchBST(root,4);
    cout<<found->val;
}
//          8
//       |     |
//      5      12
//    |   |   |   |
//   4     7 10    14