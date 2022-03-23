//https://youtu.be/Et9OCDNvJ78
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
vector<int> bottomView(TreeNode *root){
    vector<int> ans; 
    if(root == NULL) return ans; 
    map<int,int> mpp; 
    queue<pair<TreeNode*, int>> q; 
    q.push({root, 0});                      // {node,verticallevel}
    while(!q.empty()) {
        auto it = q.front(); 
        q.pop(); 
        TreeNode* node = it.first; 
        int line = it.second; 

        mpp[line] = node->val;  
            
        if(node->left != NULL) {
            q.push({node->left, line-1}); 
        }
        if(node->right != NULL) {
            q.push({node->right, line + 1}); 
        }
            
    }
        
    for(auto it : mpp) {
        ans.push_back(it.second); 
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

    vector<int>ans=bottomView(root);
 
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