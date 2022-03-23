//https://youtu.be/2r5wLmQfD6g
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
    TreeNode* markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent_track, int target_v) {
        queue<TreeNode*> queue;
        queue.push(root);
        TreeNode *target;
        while(!queue.empty()) { 
            TreeNode* current = queue.front(); 
            queue.pop();
            if(current->val == target_v){target=current;}
            if(current->left) {
                parent_track[current->left] = current;
                queue.push(current->left);
            }
            if(current->right) {
                parent_track[current->right] = current;
                queue.push(current->right);
            }
        }
        return target;
    }
public:
    int minBurnTime(TreeNode* root, int target_v) {
        unordered_map<TreeNode*, TreeNode*> parent_track; // node -> parent
        TreeNode * target = markParents(root, parent_track,target_v); 
        
        unordered_map<TreeNode*, bool> visited; 
        
        queue<TreeNode*> queue;
        queue.push(target);
        visited[target] = true;
        int time = 0;
        while(!queue.empty()) { /*Second BFS to go upto K level from target node and using our hashtable info*/
            int size = queue.size();
            bool flag =false;
            for(int i=0; i<size; i++) {
                TreeNode* current = queue.front(); queue.pop();
                if(current->left && !visited[current->left]) {
                    queue.push(current->left);
                    visited[current->left] = true;
                    flag=true;
                }
                if(current->right && !visited[current->right]) {
                    queue.push(current->right);
                    visited[current->right] = true;
                    flag=true;
                }
                if(parent_track[current] && !visited[parent_track[current]]) {
                    queue.push(parent_track[current]);
                    visited[parent_track[current]] = true;
                    flag=true;
                }
            }
            if(flag){time++;}
        }
       
        return time;
    }
};
int main(){
    TreeNode * root = new TreeNode(3);

    root->left=new TreeNode(5);   
    root->right=new TreeNode(1); 
    root->left->left=new TreeNode(6);            
    root->left->right=new TreeNode(2);
    root->right->left=new TreeNode(0);            
    root->right->right=new TreeNode(8);
    root->left->right->left =new TreeNode(7);
    root->left->right->right =new TreeNode(4);

    Solution obj;
    cout<<obj.minBurnTime(root,5);
    return 0;
}
//          3
//       |     |
//      5       4
//    |   |   |   |
//   6     2 0     8
//        ||
//       7 4