#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int data;
    TreeNode*left,*right;
    TreeNode(int val=0){
        data=val;
        left=right=NULL;
    }
};

int main(){
    TreeNode * root = new TreeNode(2);             //         2
                                           //        | |
    root->left=new TreeNode(4);                //       4   3
    root->right=new TreeNode(3);               //        |
    root->left->right=new TreeNode(5);         //         5

    return 0;
}