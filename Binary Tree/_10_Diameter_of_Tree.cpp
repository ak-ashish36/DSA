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
int findDiameter(TreeNode * root,int &maxi){
// Diameter is the longest path between two nodes of a tree
//Same code as finding height of tree
    if(root==NULL){
        return 0;
    }
    int lh=findDiameter(root->left,maxi);
    int rh =findDiameter(root->right,maxi);

    maxi=max(maxi,lh+rh);

    return 1+max(lh,rh);
}
int main(){
    TreeNode * root = new TreeNode(1);             

    root->left=new TreeNode(2);
    root->right=new TreeNode(2);
    root->left->left=new TreeNode(3);
    root->right->right=new TreeNode(3);
    root->left->left->left=new TreeNode(4);
    root->right->right->right=new TreeNode(4);
    
    int maxi=0;
    findDiameter(root,maxi);
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