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
int maxHeight(TreeNode * root){
    if(root==NULL){
        return 0;
    }
    int left=maxHeight(root->left);
    int right =maxHeight(root->right);

    return 1+max(left,right);
}
int main(){
    TreeNode * root = new TreeNode(2);             
                                           
    root->left=new TreeNode(4);   
    root->right=new TreeNode(3);   
    root->left->left=new TreeNode(7);            
    root->left->right=new TreeNode(5);         
    
    cout<<maxHeight(root);

    return 0;
}
//         2
//        | |
//       4   3
//     |  |
//    7    5