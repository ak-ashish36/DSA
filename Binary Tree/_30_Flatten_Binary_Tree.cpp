//https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
//https://youtu.be/sWf7k1x9XR4
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
        TreeNode * curr=new TreeNode();
        if(root==nullptr){return;}
        
        stack<TreeNode*>s;
        s.push(root);
        
        while(!s.empty()){
            for(int i=0;i<s.size();i++){
                TreeNode * node=s.top();
                s.pop();
                if(node->right!=nullptr){s.push(node->right);}
                if(node->left!=nullptr){s.push(node->left);}
                curr->right=node;
                curr->left=nullptr;
                curr=curr->right;
            }
        }
        root=curr->right;
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
int main(){
    TreeNode * root = new TreeNode(1);

    root->left=new TreeNode(2);   
    root->right=new TreeNode(5); 

    root->left->left=new TreeNode(3);            
    root->left->right=new TreeNode(4);
    root->right->right=new TreeNode(6);
    Solution obj;
    obj.flatten2(root);
    while(root!=nullptr){
        cout<<root->val<<" ";
        root=root->right;
    }
    return 0;
}