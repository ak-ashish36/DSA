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
int findFloor(TreeNode*root,int key){
    //floor means previous less or equal value of key 
    int floor = INT_MIN;
    while(root != NULL){
        if(root->val==key){
            floor = root->val;
            return floor;
        }
        if(root->val > key){
            root=root->left;
        }
        else{//root->val < key
            floor=root->val;         // we need value less than key therefor this is possible ans
            root=root->right;
        }
    }
    return floor;
}
int main(){
 TreeNode * root = new TreeNode(8);

    root->left=new TreeNode(5);   
    root->right=new TreeNode(12); 

    root->left->left=new TreeNode(4);            
    root->left->right=new TreeNode(7);
    root->right->left=new TreeNode(10);            
    root->right->right=new TreeNode(14);

    int ceil = findFloor(root,9);
    cout<<ceil;
}
//          8
//       |     |
//      5      12
//    |   |   |   |
//   4     7 10    14