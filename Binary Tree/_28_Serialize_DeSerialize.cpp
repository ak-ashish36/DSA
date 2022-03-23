//https://youtu.be/-YbXySKJsX8
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

string serialize(TreeNode *root){
    string ans;
    if(root==NULL) return "";

    queue<TreeNode*>q;
    q.push(root);

    while(!q.empty()){
        TreeNode *node= q.front();
        q.pop();
            
        string s;
        if(node==NULL){
            s="null,";
        }else{
            q.push(node->left);
            q.push(node->right);
            s=to_string(node->val)+",";
        }
        ans+=s;
    }
    return ans;
}
TreeNode* deserialize(string data) {
    if(data.size() == 0) return NULL; 
    //Getting value of every string after ','

    stringstream s(data);
    string str; 
    getline(s, str, ',');

    TreeNode *root = new TreeNode(stoi(str));
    queue<TreeNode*> q; 
    q.push(root); 
    while(!q.empty()) {
            
        TreeNode *node = q.front(); 
        q.pop(); 
            
        getline(s, str, ',');
        if(str != "null") {
            TreeNode* leftNode = new TreeNode(stoi(str)); 
            node->left = leftNode; 
            q.push(leftNode); 
        }

        getline(s, str, ',');
        if(str != "null") {
            TreeNode* rightNode = new TreeNode(stoi(str)); 
            node->right = rightNode;
            q.push(rightNode); 
        }
    }
    return root; 
}

void levelOrder(TreeNode *root){
    if(root==NULL) return;
    queue<TreeNode*>q;
    q.push(root);

    while(!q.empty()){
        int size =q.size();
        vector<int>level;
        for (int i=0;i<size;i++){
            TreeNode *node= q.front();
            q.pop();
            if(node->left!=NULL){
                q.push(node->left);
            }
            if(node->right!=NULL){
                q.push(node->right);
            }
            cout<<(node->val)<<" ";
        }
    }
    cout<<endl;
}
int main(){
    TreeNode * root = new TreeNode(2);             
                                           
    root->left=new TreeNode(4);   
    root->right=new TreeNode(3);   
    root->left->left=new TreeNode(7);            
    root->left->right=new TreeNode(5); 

    string ans=serialize(root);

    TreeNode *root2= deserialize(ans);
    levelOrder(root);
    levelOrder(root2);
    return 0;
}
//         2
//        | |
//       4   3
//     |  |
//    7    5