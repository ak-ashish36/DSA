//https://youtu.be/sWf7k1x9XR4
#include<bits/stdc++.h>
using namespace std;
class Solution {
    TreeNode* prev = NULL;
public:
    // T =O(N)  S= O(N)
    void flatten1(TreeNode* root) {
        if(root == NULL) return; 
        
        flatten1(root->right); 
        flatten1(root->left); 
        
        root->right = prev;
        root->left = NULL; 
        prev = root; 
    }
    // T =O(N)  S= O(N)
    void flatten2(TreeNode* root) {
        if(root == NULL) return; 
        stack<TreeNode*> st; 
        st.push(root); 
        while(!st.empty()) {
            TreeNode* cur = st.top(); 
            st.pop(); 
            
            if(cur->right != NULL) {
                st.push(cur->right); 
            }
            if(cur->left != NULL) {
                st.push(cur->left); 
            }
            if(!st.empty()) {
                cur->right = st.top(); 
            }
            cur->left = NULL;
        }
        
    }

    // T =O(N)  S= O(1)
    void flatten3(TreeNode* root) {
    TreeNode* cur = root;
	while (cur != NULL){
		if(cur->left != NULL){
			TreeNode* pre = cur->left;
			while(pre->right != NULL){
				pre = pre->right;
			}
			pre->right = cur->right;
			cur->right = cur->left;
			cur->left = NULL;
		}
		cur = cur->right;
	}
}
};
struct TreeNode{
    int val;
    TreeNode*left,*right;
    TreeNode(int val=0){
        this->val=val;
        left=right=NULL;
    }
};

int main(){
     
    return 0;
}