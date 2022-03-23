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

vector<vector<int>>levelOrder(TreeNode *root){
    vector<vector<int>>ans;
    if(root==NULL) return ans;

    queue<TreeNode*>q;
    q.push(root);

    while(!q.empty()){
        int size =q.size();
        vector<int>level;
        for (int i=0;i<size;i++){
            TreeNode *node= q.front();
            q.pop();
            if(node->left!=NULL){
                q.push(node->left);
            }
            if(node->right!=NULL){
                q.push(node->right);
            }
            level.push_back(node->val);
        }
        ans.push_back(level);
    }
    return ans;
}
int main(){
    TreeNode * root = new TreeNode(2);             
                                           
    root->left=new TreeNode(4);   
    root->right=new TreeNode(3);   
    root->left->left=new TreeNode(7);            
    root->left->right=new TreeNode(5); 
              
    vector<vector<int>>ans=levelOrder(root);

    for(vector<int> i:ans){
        for(int j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
//         2
//        | |
//       4   3
//     |  |
//    7    5