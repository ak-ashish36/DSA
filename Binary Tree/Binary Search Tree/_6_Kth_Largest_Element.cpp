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
    void inOrderTraversal(TreeNode *root,int k,int&count,int&ans){
        if(root==NULL){
            return;
        }
        inOrderTraversal(root->left,k,count,ans);
        count++;
        if(count==k){
            ans =root->val;
        }
        inOrderTraversal(root->right,k,count,ans);
    }

    int kthSmallest(TreeNode* root, int k) {
        int count=0;
        int ans=-1;
        inOrderTraversal(root,k,count,ans);
        return ans;
        
    }
};
int main(){
    TreeNode * root = new TreeNode(8);

    root->left=new TreeNode(5);   
    root->right=new TreeNode(12); 

    root->left->left=new TreeNode(4);            
    root->left->right=new TreeNode(7);
    root->right->left=new TreeNode(10);            
    root->right->right=new TreeNode(14);

    Solution obj;
    cout<<obj.kthSmallest(root,5);
    return 0;
}