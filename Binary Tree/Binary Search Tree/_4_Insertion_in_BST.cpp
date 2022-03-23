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
TreeNode * insert(TreeNode* root, int val) {
    if(root == NULL){
       root = new TreeNode(val);
       return root;
    }

    TreeNode*temp=root;
    while(true){
        if(temp->val >= val){
            if(temp->left == NULL){
                temp->left=new TreeNode(val);
                break;
            }
            temp=temp->left;
        }
        else{ // temp->val < val
            if(temp->right == NULL){
                temp->right=new TreeNode(val);
                break;
            }
            temp=temp->right;
        }
    }
    return root;
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
 TreeNode * root = new TreeNode(8);

    root->left=new TreeNode(5);   
    root->right=new TreeNode(12); 

    root->left->left=new TreeNode(4);            
    root->left->right=new TreeNode(7);
    root->right->left=new TreeNode(10);            
    root->right->right=new TreeNode(14);

    inOrderTraversal(root);
    insert(root,13);
    cout<<endl;
    inOrderTraversal(root);

    
}
//          8
//       |     |
//      5      12
//    |   |   |   |
//   4     7 10    14