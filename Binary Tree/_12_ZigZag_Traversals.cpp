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

vector<vector<int>>zigzagOrder(TreeNode *root){
    vector<vector<int>>ans;
    if(root==NULL) return ans;
    queue<TreeNode*>q;
    q.push(root);

    bool flag = true;   // true - L-> R   and false=R->L

    while(!q.empty()){
        int size =q.size();
        vector<int>level(size);
        for (int i=0;i<size;i++){
            TreeNode *node= q.front();
            q.pop();
            if(node->left!=NULL){
            q.push(node->left);
            }
            if(node->right!=NULL){
            q.push(node->right);
            }
            int index=(flag==true)?i:size-1-i;          // if flag=false  insert in reverse order
            level[index]=node->val;
        }
        flag=!flag;     //Reverse Flag
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
    root->left->left->left=new TreeNode(9);  
    root->left->left->right=new TreeNode(10);
              
   vector<vector<int>>ans=zigzagOrder(root);

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
//   | |
//  9  10