//https://youtu.be/fnmisPM6cVo
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
/*Self Notes 📜:
🥥 if both children values sum is greater than or equal to parent, make parent's value to children's sum.
🥥 if both children sum is less than parent, make children's value to parent's value.
🥥 recursively go left and right. Traversal type: DFS.
🥥 when coming back up the tree, take children sum and replace it in parent.
🥥 at any point we reach null, just return (base case)
🥥 Intuition: while going down, increase the children values so we make sure to never fall short, then all we have to do is sum both children and replace it in parent.*/
void reorder(TreeNode * root) {
    if(root == NULL) return; 
    int child = 0;
    if(root->left) {
        child += root->left->val; 
    }
    if(root->right) {
        child += root->right->val; 
    }
    
    if(child >= root->val) root->val = child; 
    else {
        if(root->left) root->left->val = root->val; 
        else if(root->right) root->right->val = root->val; 
    }
    
    reorder(root->left); 
    reorder(root->right); 
    
    int tot = 0; 
    if(root->left) tot += root->left->val; 
    if(root->right) tot+= root->right->val; 
    if(root->left or root->right) root->val = tot;  
}
int main(){
 TreeNode * root = new TreeNode(1);

    root->left=new TreeNode(2);   
    root->right=new TreeNode(2); 

    root->left->left=new TreeNode(4);            
    root->left->right=new TreeNode(5);
    root->right->left=new TreeNode(5);            
    root->right->right=new TreeNode(4);

    reorder(root);

    cout<<root->val;
}
//          1
//       |     |
//      2       2
//    |   |   |   |
//   4     5 5     4