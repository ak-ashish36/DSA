//https://youtu.be/ZbybYvcVLks
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
int widthOfBinaryTree(TreeNode* root) {
    if(root==NULL) return 0;
    int ans = 0;

    queue<pair<TreeNode*, int>> q;
    q.push({root,0});

    while(!q.empty()){
        int size = q.size();
        int mmin = q.front().second;    //to make the id starting from zero
        int first,last;
        for(int i=0; i<size; i++){
            int cur_id = q.front().second-mmin;
            TreeNode* node = q.front().first;
            q.pop();

            if(i==0) first = cur_id;
            if(i==size-1) last = cur_id;

            if(node->left)
                q.push({node->left, cur_id*2+1});
            if(node->right)
                q.push({node->right, cur_id*2+2});
        }
        ans = max(ans, last-first+1);
    }
    return ans;
}
int main(){
 TreeNode * root = new TreeNode(1);

    root->left=new TreeNode(2);   
    root->right=new TreeNode(2); 

    root->left->left=new TreeNode(4);            
    root->left->right=new TreeNode(5);
    root->right->left=new TreeNode(5);            
    root->right->right=new TreeNode(4);

    cout<<widthOfBinaryTree(root);
}
//          1
//       |     |
//      2       2
//    |   |   |   |
//   4     5 5     4