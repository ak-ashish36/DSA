//https://youtu.be/q_a6lpbKJdw
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
vector<vector<int>> verticalOrder(TreeNode*root){
    map<int, map<int, multiset<int>>> mpp;
    queue<pair<TreeNode*, pair<int, int>>> q;
    q.push({root, {0, 0}});
    
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        TreeNode* node = p.first;
        int x = p.second.first, y = p.second.second;
        mpp[x][y].insert(node -> val);
        if (node->left !=NULL) {
            q.push({node -> left, {x - 1, y + 1}});
        }
        if (node->right !=NULL) {
            q.push({node -> right, {x + 1, y + 1}});
        }
    }
    vector<vector<int>> ans;
    for (auto p : mpp) {
        vector<int> col;
        for (auto q : p.second) {
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(col);
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

    vector<vector<int>>ans=verticalOrder(root);
    for(vector<int>i : ans){
        for(int j:i){
         cout<<j<<" ";
        }
        cout<<endl;
    }                                                  
    return 0;
}
//          1
//       |     |
//      2       3
//    |   |   |   |
//   4     5 6     7