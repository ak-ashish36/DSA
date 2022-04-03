// https://youtu.be/A8ko93TyOns
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkForCycle(int s, vector<vector<int>>&adj, vector<int>& visited){ 
        // Create a queue for BFS
        queue<pair<int,int>> q;
     
        visited[s] = true;
        q.push({s, -1});
     
        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (auto it : adj[node]) {
                if (!visited[it]) {
                    visited[it] = true;
                    q.push({it, node});
                }
                else if (it != parent){       // it is already visited and not equal to parent it means there is cycle
                    return true;
                }
            }
        }
        return false;
    }
public:
	bool isCycle(int V, vector<vector<int>>&adj){
	    vector<int> vis(V, 0); 
	    for(int i = 0;i<V;i++) {
	        if(!vis[i]) {
	            if(checkForCycle(i,adj, vis)){
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