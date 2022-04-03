#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkForCycle(int node, int parent, vector<vector<int>>&adj, vector<int>& vis){ 
        vis[node] = 1; 
        for(auto it: adj[node]) {
            if(!vis[it]) {
                if(checkForCycle(it,node,adj,vis)) 
                    return true; 
            }
            else if(it!=parent)
                return true; 
        }
        return false; 
    }
    bool isCycle(int V, vector<vector<int>>&adj) {
        vector<int> vis(V, 0); 
	    for(int i = 0;i<V;i++) {
	        if(!vis[i]) {
	            if(checkForCycle(i, -1, adj, vis)){
                    return true;
                }  
	        }
	    }
	    return false; 
    }
};
void addEdge(vector<vector<int>>&adj,int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int main(){
    vector<vector<int>>adj(5);
   
    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,2,3);
    addEdge(adj,1,3);
    addEdge(adj,2,4);
   
    Solution obj;
    cout<<obj.isCycle(5, adj);
 
    return 0;
}