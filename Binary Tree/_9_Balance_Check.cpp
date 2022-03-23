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
bool balanceCheck(TreeNode*root){
    if(root==NULL) return true;

    int left_height=maxHeight(root->left);
    int right_height=maxHeight(root->right);

    if(abs(left_height-right_height) >1){
        return false;
    }

    bool left_check=balanceCheck(root->left);
    bool right_check=balanceCheck(root->right);

    if(left_check==false || right_check==false){
        return false;
    }
    return true;

}
int main(){
    TreeNode * root = new TreeNode(1);             

    root->left=new TreeNode(2);
    root->right=new TreeNode(2);
    root->left->left=new TreeNode(3);
    root->right->right=new TreeNode(3);
    root->left->left->left=new TreeNode(4);
    root->right->right->right=new TreeNode(4);
    
    cout<<balanceCheck(root);

    return 0;
}
//         1
//        | |
//       2   2
//     |      |
//    3        3
//   |          |
//  4            4