//https://youtu.be/2YBhNLodD8Q
//https://youtu.be/NzIGLLwZBS8
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
//T=O(2n)  S=O(2n)
vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        if(root == NULL) return postorder;
        stack<TreeNode*> st1, st2; 
        st1.push(root); 
        while(!st1.empty()) {
            root = st1.top(); 
            st1.pop();
            st2.push(root); 
            if(root->left != NULL) {
                st1.push(root->left); 
            }
            if(root->right != NULL) {
                st1.push(root->right); 
            }
        }
        while(!st2.empty()) {
            postorder.push_back(st2.top()->val); 
            st2.pop(); 
        }
        return postorder;
}
//Better Space Optimization T=O(2n)  S=O(n)
vector<int> postorderTraversal2(TreeNode* root) {
    vector<int> postorder;
    if(root == NULL) return postorder;
    stack<TreeNode*> st1;
    TreeNode* current = root;  
    
    while(current != NULL || !st1.empty()) {
        if(current != NULL){
            st1.push(current);
            current = current->left;
        }else{
            TreeNode* temp = st1.top()->right;
            if (temp == NULL) {
                temp = st1.top();
                st1.pop(); 
                postorder.push_back(temp->val);
                while (!st1.empty() && temp == st1.top()->right) {
                    temp = st1.top();
                    st1.pop(); 
                    postorder.push_back(temp->val);
                }
            } else {
                current = temp;
            }
        }
    }
    return postorder;
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
//         2
//        | |
//       4   3
//     |  |
//    7    5