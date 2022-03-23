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
// Use Level order Traversal and insert last elemnt of each level into your answer for right view
vector<int> rightView(TreeNode*root){
    vector<int>ans;
    if(root==NULL) return ans;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        int size =q.size();
        int x=0;
        for(int i=0;i<size;i++){
            TreeNode*node =q.front();
            q.pop();
            if(node->left!=NULL){
                q.push(node->left);
            }
            if(node->right!=NULL){
                q.push(node->right);
            }
            x=node->val;
        }
        ans.push_back(x);
    }
    return ans;
}
// Use Reverse Level order Traversal and insert last elemnt of each level into your answer for left view
vector<int> leftView(TreeNode*root){
    vector<int>ans;
    if(root==NULL) return ans;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        int size =q.size();
        int x=0;
        for(int i=0;i<size;i++){
            TreeNode*node =q.front();
            q.pop();
            if(node->right!=NULL){
                q.push(node->right);
            }
            if(node->left!=NULL){
                q.push(node->left);
            }
            x=node->val;
        }
        ans.push_back(x);
    }
    return ans;
}
int main(){
 TreeNode * root = new TreeNode(1);

    root->left=new TreeNode(2);   
    root->right=new TreeNode(3); 

    root->left->left=new TreeNode(4);            
    root->left->right=new TreeNode(5);
    root->right->left=new TreeNode(6);            
    root->right->right=new TreeNode(7);

    vector<int>ans=leftView(root);
 
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