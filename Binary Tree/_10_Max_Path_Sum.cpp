// Diameter is the longest path between two nodes of a tree
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
//  T=O(n)
int maxPathsum(TreeNode * root,int &maxi){
// Diameter is the longest path between two nodes of a tree
//Same code as finding height of tree
    if(root==NULL){
        return 0;
    }
    int leftSum= max(0, maxPathsum(root->left,maxi));
    int rightSum =max(0, maxPathsum(root->right,maxi));

    maxi=max(maxi,leftSum+rightSum+root->val);

    return root->val+max(leftSum,rightSum);
}
int main(){
    TreeNode * root = new TreeNode(1);             

    root->left=new TreeNode(2);
    root->right=new TreeNode(2);
    root->left->left=new TreeNode(3);
    root->right->right=new TreeNode(3);
    root->left->left->left=new TreeNode(4);
    root->right->right->right=new TreeNode(4);
    
    int maxi=INT_MIN;
    maxPathsum(root,maxi);
    cout<<maxi;

    return 0;
}
//         1
//        | |
//       2   2
//     |      |
//    3        3
//   |          |
//  4            4