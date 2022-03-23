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
public:
    BSTIterator(TreeNode *root) {
        pushAllLeft(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !myStack.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *tmpNode = myStack.top();
        myStack.pop();
        pushAllLeft(tmpNode->right);
        return tmpNode->val;
    }

private:
    void pushAllLeft(TreeNode *node) {
        while(node!=NULL){
            myStack.push(node);
            node = node->left;
        }
    }
};
// for finding before element in inorder
class BSTIterator2 {
    stack<TreeNode *> myStack;
public:
    BSTIterator2(TreeNode *root) {
        pushAllRight(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !myStack.empty();
    }

    /** @return the next smallest number */
    int prev() {
        TreeNode *tmpNode = myStack.top();
        myStack.pop();
        pushAllRight(tmpNode->left);
        return tmpNode->val;
    }

private:
    void pushAllRight(TreeNode *node) {
        while(node!=NULL){
            myStack.push(node);
            node = node->right;
        }
    }
};
int main(){
 TreeNode * root = new TreeNode(8);

    root->left=new TreeNode(5);   
    root->right=new TreeNode(12); 

    root->left->left=new TreeNode(4);            
    root->left->right=new TreeNode(7);
    root->right->left=new TreeNode(10);            
    root->right->right=new TreeNode(14);

   BSTIterator obj(root);
   cout<<obj.next()<<" ";
   cout<<obj.next()<<" ";
   cout<<obj.next()<<" ";

   cout<<endl;

   BSTIterator2 obj2(root);
   cout<<obj2.prev()<<" ";
   cout<<obj2.prev()<<" ";
   cout<<obj2.prev()<<" ";



}
//          8
//       |     |
//      5      12
//    |   |   |   |
//   4     7 10    14