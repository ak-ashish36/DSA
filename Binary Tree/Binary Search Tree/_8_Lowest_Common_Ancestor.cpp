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
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root) return NULL;
    int curr = root->val; 
    if(curr < p->val && curr < q->val) {
    return lowestCommonAncestor(root->right, p, q);
    }
    if(curr > p->val && curr > q->val) {
        return lowestCommonAncestor(root->left, p, q);
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
    root->right->right=new TreeNode(16);

    TreeNode *lca=lowestCommonAncestor(root, root->left->left, root->left->right);   
    cout<<lca->val;                                    
    return 0;
}
//          8
//       |     |
//      5      12
//    |   |   |   |
//   4     7 10    14