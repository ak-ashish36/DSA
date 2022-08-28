//https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
//https://youtu.be/A8ko93TyOns  -BFS
//https://youtu.be/Y9NFqI6Pzd4  -DFS
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool bfsCheck(int i, vector<vector<int>>&adj, vector<int>& visited){ 
        queue<pair<int,int>> q;
        visited[i] = true;
        //Initially parent is -1
        q.push({i, -1});
     
        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (auto it : adj[node]) {
                if (!visited[it]) {
                    visited[it] = true;
                    q.push({it, node});
                }
                else if(parent !=-1 && it != parent){// it is already visited and not equal to parent it means there is cycle
                    return true;
                }
            }
        }
        return false;
    }
    bool dfsCheck(int node, int parent, vector<vector<int>>&adj, vector<int>&visited){ 
        visited[node] = 1; 
        for(auto it: adj[node]) {
            if(!visited[it]) {
                if(dfsCheck(it,node,adj,visited)) 
                    return true; 
            }
            else if(parent !=-1 && it != parent)
                return true; 
        }
        return false; 
    }
public:
	bool isCycle(int V, vector<vector<int>>&adj){
	    vector<int> visited(V, 0); 
	    for(int i = 0;i<V;i++) {
	        if(!visited[i]) {
	            if(bfsCheck(i,adj,visited)){
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
    //Output =True there is cycle {0,1,3,2}
    Solution obj;
    cout<<obj.isCycle(adj.size(), adj);
    return 0;
}