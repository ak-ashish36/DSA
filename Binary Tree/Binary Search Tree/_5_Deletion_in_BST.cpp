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
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) return NULL;
    
        if (root->val == key) {
            return deletion(root);
        }
        //Finding the node
        TreeNode *dummy = root;
        while (root != NULL) {
            if (root->val > key) {
                if (root->left != NULL && root->left->val == key) {
                    root->left = deletion(root->left);
                    break;
                } else {
                    root = root->left;
                }
            } else {
                if (root->right != NULL && root->right->val == key) {
                    root->right = deletion(root->right);
                    break;
                } else {
                    root = root->right;
                }
            }
        }
        return dummy;
    }
    TreeNode* deletion(TreeNode* root) {
            if (root->left == NULL) {
                return root->right;
            } 
            else if (root->right == NULL){
                return root->left;
            } 
            TreeNode* rightChild = root->right;
            TreeNode* lastRight =inOrderPrecedence(root);
            lastRight->right = rightChild;
            return root->left;
    }

    TreeNode* inOrderPrecedence(TreeNode* root) {  //inOrder Predecessor is the rightmost node of the left subtree of the root
        root=root->left;
        while(root->right!=NULL){
            root=root->right;
        }
        return root;
    }
};

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
    Solution obj;

    inOrderTraversal(root);
    obj.deleteNode(root,12);
    cout<<endl;
    inOrderTraversal(root);

}
//          8
//       |     |
//      5      12
//    |   |   |   |
//   4     7 10    14