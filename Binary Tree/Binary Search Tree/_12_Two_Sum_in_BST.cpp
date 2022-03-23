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
class BSTIterator {
    stack<TreeNode *> myStack;
    bool reverse =false;         //false = next   true=prev
public:
    BSTIterator(TreeNode *root, bool isReverse) {
        reverse=isReverse;
        pushAll(root);
    }

    bool hasNext() {
        return !myStack.empty();
    }

    int next() {
        TreeNode *tmpNode = myStack.top();
        myStack.pop();
        if(reverse==false){pushAll(tmpNode->right);}
        else{pushAll(tmpNode->left);}
        return tmpNode->val;
    }

    void pushAll(TreeNode *node) {
        while(node!=NULL){
            myStack.push(node);
            if(reverse==false){node = node->left;}
            if(reverse==true){node=node->right;}
        }
    }
};
bool findTarget(TreeNode* root, int k) {
        if(!root) return false; 
        BSTIterator l(root, false); //will find next
        BSTIterator r(root, true);  //will find prev
        
        int i = l.next(); 
        int j = r.next(); 
        while(i<j) {
            if(i + j == k) return true; 
            else if(i + j < k) i = l.next(); 
            else j = r.next(); 
        }
        return false; 
    }
int main(){
     
    return 0;
}