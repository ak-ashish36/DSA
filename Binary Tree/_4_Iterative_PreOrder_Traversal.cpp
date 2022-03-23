//https://youtu.be/EoAsWbO7sqg
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
vector<int> preOrder(TreeNode *root){
    // Root - Left - Right
    vector<int>ans;
    if(root==NULL) return ans;

    stack<TreeNode*>s;
    s.push(root);

    while(!s.empty()){
        
        for (int i=0;i< s.size();i++){
            TreeNode *node= s.top();
            s.pop();
            
            if(node->right!=NULL){
                s.push(node->right);
            }
            if(node->left!=NULL){
                s.push(node->left);
            }

            ans.push_back(node->val);
        }
    }
    return ans;
}
int main(){
    TreeNode * root = new TreeNode(2);             
                                           
    root->left=new TreeNode(4);   
    root->right=new TreeNode(3);   
    root->left->left=new TreeNode(7);            
    root->left->right=new TreeNode(5);         
    
    vector<int>ans=preOrder(root);

    for(int i:ans){
        cout<<i<<" ";
    }
    return 0;
}
//         2
//        | |
//       4   3
//     |  |
//    7    5