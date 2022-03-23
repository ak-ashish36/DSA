//https://youtu.be/lxTGsVXjwvM
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

vector<int> inOrderTraversal( TreeNode*root) {
    // Left- Root - Right
    stack<TreeNode*> st; 
    TreeNode* node = root;
    vector<int> ans; 

    while(true) {
        if(node != NULL) {
            st.push(node); 
            node = node->left; 
        }
        else {

            if(st.empty() == true) break; 
            node = st.top(); 
            st.pop(); 
            ans.push_back(node->val); 
            node = node->right; 
        }  
    }
    return ans; 
}
int main(){
    TreeNode *root = new TreeNode(2);             
                                           
    root->left=new TreeNode(4);   
    root->right=new TreeNode(3);   
    root->left->left=new TreeNode(7);            
    root->left->right=new TreeNode(5);         
    
    vector<int>ans=inOrderTraversal(root);
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