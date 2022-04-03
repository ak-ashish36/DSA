//https://youtu.be/uzVUw90ZFIg
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkForCycle(int node,vector<vector<int>>&adj, vector<int>& vis,vector<int>&dfsvis){ 
        vis[node] = 1; 
        dfsvis[node]=1;
        for(auto it: adj[node]) {
            if(!vis[it]) {
                if(checkForCycle(it,adj,vis,dfsvis)) 
                    return true; 
            }
            else if(dfsvis[node])
                return true; 
        }
        dfsvis[node]=0;
        return false; 
    }
    bool isCycle(int V, vector<vector<int>>&adj) {
        vector<int> vis(V, 0);
        vector<int> dfsvis(V, 0); 
	    for(int i = 0;i<V;i++) {
	        if(!vis[i]) {
	            if(checkForCycle(i,adj,vis,dfsvis)){
                    return true;
                }  
	        }
	    }
	    return false; 
    }
};
void addEdge(vector<vector<int>>&adj,int u,int v){
    adj[u].push_back(v);
}
int main(){
    vector<vector<int>>adj(5);
    addEdge(adj,1,0);
    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,2,3);
    addEdge(adj,1,3);
    addEdge(adj,2,4);
   
    Solution obj;
    cout<<obj.isCycle(5, adj);
    return 0;
}