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
TreeNode*lowestCommonAncestor(TreeNode*root,TreeNode*p,TreeNode*q){
    if(root==NULL || root == p || root==q){
        return root;
    }
    TreeNode*left =lowestCommonAncestor(root->left,p,q);
    TreeNode*right =lowestCommonAncestor(root->right,p,q);

    if(left==NULL){ 
        return right;
    }
    else if(right==NULL){
        return left;
    }
    else{   // both are not null it means we have found p and q
        return root;
    }

}
int main(){
    TreeNode * root = new TreeNode(1);

    root->left=new TreeNode(2);   
    root->right=new TreeNode(3); 

    root->left->left=new TreeNode(4);            
    root->left->right=new TreeNode(5);
    root->right->left=new TreeNode(6);            
    root->right->right=new TreeNode(7);

    TreeNode *lca=lowestCommonAncestor(root,root->left->left,root->left->right);   
    cout<<lca->val;                                    
    return 0;
}
//          1
//       |     |
//      2       3
//    |   |   |   |
//   4     5 6     7
