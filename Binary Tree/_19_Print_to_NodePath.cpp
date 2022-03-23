//https://youtu.be/fmflMqVOC7k
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
bool getPath(TreeNode*root,vector<int>&arr,int x){
    if(root==NULL){
        return false;
    }
    arr.push_back(root->val);
    if(root->val==x){
        return true;
    }
    if(getPath(root->left,arr,x) || getPath(root->right,arr,x)){
        return true;
    }
    arr.pop_back();
    return false;
}
vector<int>printPath(TreeNode*root,int x){
    vector<int>ans;
    getPath(root,ans,x);
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

    vector<int>ans=printPath(root,5);
 
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