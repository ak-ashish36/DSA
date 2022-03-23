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
bool check(TreeNode*root1, TreeNode*root2){
    if(root1==NULL || root2==NULL){
        if(root1==root2) return true;
        return false;
    }
    bool valcheck =(root1->val == root2->val);
    return valcheck && check(root1->left,root2->left) && check(root1->right,root2->right);

};
int main(){
    TreeNode *root1 = new TreeNode(2);                                                   
    root1->left=new TreeNode(4);   
    root1->right=new TreeNode(3);   
    root1->left->left=new TreeNode(7);            
    root1->left->right=new TreeNode(5);   

    TreeNode *root2 = new TreeNode(2);                                                   
    root2->left=new TreeNode(4);   
    root2->right=new TreeNode(3);   
    root2->left->left=new TreeNode(7);            
    root2->left->right=new TreeNode(5);  

    cout<<check(root1,root2);      
    
   
     
    return 0;
}