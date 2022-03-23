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
int findCeil(TreeNode*root,int key){
    //ceil means next greater or equal value of key 
    int ceil = INT_MIN;
    while(root != NULL){
        if(root->val==key){
            ceil = root->val;
            return ceil;
        }
        if(root->val < key){
            root=root->right;
        }
        else{//root->val > key
            ceil=root->val;         // we need value greater than key therefor this is possible ans
            root=root->left;
        }
    }
    return ceil;
}
int main(){
 TreeNode * root = new TreeNode(8);

    root->left=new TreeNode(5);   
    root->right=new TreeNode(12); 

    root->left->left=new TreeNode(4);            
    root->left->right=new TreeNode(7);
    root->right->left=new TreeNode(10);            
    root->right->right=new TreeNode(14);

    int ceil = findCeil(root,6);
    cout<<ceil;
}
//          8
//       |     |
//      5      12
//    |   |   |   |
//   4     7 10    14