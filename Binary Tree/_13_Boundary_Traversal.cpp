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
bool isLeaf(TreeNode*root){
    if(root->left==NULL && root->right==NULL)
        return true;
    return false;
}
void addLeftBoundary(TreeNode*root,vector<int>&result){
    TreeNode*curr=root->left;
    while(curr!=NULL){
        if(!isLeaf(curr)){
            result.push_back(curr->val);
        }
        if(curr->left!=NULL)
            curr=curr->left;
        else
            curr=curr->right;
    }
}
void addRightBoundary(TreeNode*root,vector<int>&result){
    TreeNode*curr=root->right;
    stack<int>s;
    while(curr!=NULL){
        if(!isLeaf(curr)){
            s.push(curr->val);
        }
        if(curr->right!=NULL)
            curr=curr->right;
        else
            curr=curr->left;
    }
    while(!s.empty()){
        result.push_back(s.top());
        s.pop();
    }
}
void addLeaveNodes(TreeNode*root,vector<int>&result){
    if(isLeaf(root)){
        result.push_back(root->val);
        return;
    }
    if(root->left!=NULL){
        addLeaveNodes(root->left,result);
    }
    if(root->right!=NULL){
        addLeaveNodes(root->right,result);
    }
}
vector<int> boundaryTraversal(TreeNode*root){
    vector<int>ans;
    if(root==NULL) return ans;
    else if(!isLeaf(root)){
        ans.push_back(root->val);
    }

    addLeftBoundary(root,ans);
    addLeaveNodes(root,ans);
    addRightBoundary(root,ans);


    return ans;
}
int main(){
    TreeNode * root = new TreeNode(100); 
    root->left=new TreeNode(50);   
    root->right=new TreeNode(150);   
    root->left->left=new TreeNode(25);            
    root->left->right=new TreeNode(75);
    root->right->left=new TreeNode(140);            
    root->right->right=new TreeNode(200);

    root->left->left->right=new TreeNode(30);
    root->left->right->left =new TreeNode(70);
    root->left->right->right =new TreeNode(80);

    root->left->left->right->right=new TreeNode(35);


    vector<int>ans=boundaryTraversal(root);
    for(int i:ans){
        cout<<i<<" ";
    }                                                  
    return 0;
}
//         100
//        |   |
//      50     150
//     |  |    | |
//    25   75  140 200
//      |  | |
//     30 70 80
//       |
//       35