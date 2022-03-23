//https://youtu.be/80Zug6D1_r4
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder; 
        
        TreeNode* cur = root; 
        while(cur != NULL) {
            
            if(cur->left == NULL) {
                inorder.push_back(cur->val); 
                cur = cur->right; 
            }
            else {
                TreeNode* prev = cur->left; 
                while(prev->right != NULL && prev->right != cur) {
                    prev = prev->right; 
                }
                
                if(prev->right == NULL) {
                    prev->right = cur;
                    cur = cur->left; 
                }
                else {
                    prev->right = NULL; 
                    inorder.push_back(cur->val); 
                    cur = cur->right; 
                }
            }
        }
        return inorder; 
    }
};
int main(){
    TreeNode * root = new TreeNode(1);

    root->left=new TreeNode(2);   
    root->right=new TreeNode(3); 

    root->left->left=new TreeNode(4);            
    root->left->right=new TreeNode(5);
    root->right->left=new TreeNode(6);            
    root->right->right=new TreeNode(7);

    Solution obj;

    vector<int>ans=obj.inorderTraversal(root);
 
    for(int i:ans){
     cout<<i<<" ";
    }
        cout<<endl;                                            
    return 0;
}
//          1
//       |     |
//      2       3
//    |   |   |   |
//   4     5 6     7