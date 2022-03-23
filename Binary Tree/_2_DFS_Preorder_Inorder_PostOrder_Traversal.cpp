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

void postOrderTraversal(TreeNode *root){
    // Left - Right- Root
    if(root==NULL){
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->val<<" ";
}
int main(){
    TreeNode * root = new TreeNode(2);             
                                           
    root->left=new TreeNode(4);   
    root->right=new TreeNode(3);   
    root->left->left=new TreeNode(7);            
    root->left->right=new TreeNode(5);         
    preOrderTraversal(root);
    cout<<endl;
    inOrderTraversal(root);
    cout<<endl;
    postOrderTraversal(root);
    cout<<endl;
    return 0;
}
//         2
//        | |
//       4   3
//     |  |
//    7    5