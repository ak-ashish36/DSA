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
vector<int> topView(TreeNode *root){
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
        if(mpp.find(line) == mpp.end()){
            mpp[line] = node->val;  
        }
            
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

    root->left->left->left=new TreeNode(8);
    root->left->left->right=new TreeNode(9);
    root->left->right->left =new TreeNode(10);
    root->left->right->right =new TreeNode(11);
    root->right->left->left =new TreeNode(12);
    root->right->left->right =new TreeNode(13);
    root->right->right->left =new TreeNode(14);
    root->right->right->right =new TreeNode(15);

    vector<int>ans=topView(root);
 
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
//  | |   | || |  | |
// 8   9 10111213 14 15