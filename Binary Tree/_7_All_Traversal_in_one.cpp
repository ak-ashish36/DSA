//https://youtu.be/ySp2epYvgTE
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
vector<int> postorderTraversal(TreeNode* root) {
    stack<pair<TreeNode*,int>> st; 
    st.push({root, 1}); 
    vector<int> pre, in, post;
    if(root == NULL) return post;

    while(!st.empty()) {
        auto it = st.top(); 
        st.pop(); 

        // this is part of pre
        // increment 1 to 2 
        // push the left side of the tree
        if(it.second == 1) {
            pre.push_back(it.first->val); 
            it.second++; 
            st.push(it); 

            if(it.first->left != NULL) {
                    st.push({it.first->left, 1}); 
            }
        }

        // this is a part of in 
        // increment 2 to 3 
        // push right 
        else if(it.second == 2) {
            in.push_back(it.first->val); 
            it.second++; 
            st.push(it); 

            if(it.first->right != NULL) {
                    st.push({it.first->right, 1}); 
            }
        }
        // don't push it back again 
        else {
            post.push_back(it.first->val); 
        }
    } 

    return post; 
}
int main(){
    TreeNode *root = new TreeNode(2);             
                                           
    root->left=new TreeNode(4);   
    root->right=new TreeNode(3);   
    root->left->left=new TreeNode(7);            
    root->left->right=new TreeNode(5);         
    
    vector<int>ans=postorderTraversal(root);
    for(int i:ans){
        cout<<i<<" ";
    }
    return 0;
}