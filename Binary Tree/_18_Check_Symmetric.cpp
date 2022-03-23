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
bool check(TreeNode* left, TreeNode*right){
    if(right ==NULL || left == NULL){
        if(right==left)
            return true;
        return false;
    }
    if(left->val != right->val) return false;
    return check(left->left,right->right) && check(left->right,right->left);
};
bool isSymmetric(TreeNode* root) {
    if(root==NULL) return true;
    return check(root->left,root->right);    
}
int main(){
 TreeNode * root = new TreeNode(1);

    root->left=new TreeNode(2);   
    root->right=new TreeNode(2); 

    root->left->left=new TreeNode(4);            
    root->left->right=new TreeNode(5);
    root->right->left=new TreeNode(5);            
    root->right->right=new TreeNode(4);

    cout<<isSymmetric(root);
}
//          1
//       |     |
//      2       2
//    |   |   |   |
//   4     5 5     4