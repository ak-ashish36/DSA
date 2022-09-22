//https://practice.geeksforgeeks.org/problems/bipartite-graph/1
//https://youtu.be/nbgaEu-pvkU  -BFS
//https://youtu.be/uC884ske2uQ  -DFS
// Graph that can  be colored with two colors such that no two adjacent node have same color
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool bfs(int i,vector<vector<int>>&adj, vector<int>& color){ 
        queue<int> q;
        color[i] = 1;
        q.push(i);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto it : adj[node]) {
                if (color[it]==-1) {
                    color[it] = 1-color[node] ;
                    q.push(it);
                }
                else if (color[it] == color[node]){  //if adjacent colors are same return false
                    return false;
                }
            }
        }
        return true;
    }
    bool dfs(int node,vector<vector<int>>&adj, vector<int>& color){
        for (auto it : adj[node]) {
            if (color[it]==-1) {
                color[it] = 1 - color[node];
                if(!dfs(it, adj, color)) {
                    return false; 
                }
            }
            else if (color[it] == color[node]){    //if adjacent colors are same return false
                return false;
            }
        }
        return true;
    }
public:
	bool isBipartite(int V,vector<vector<int>>&adj){
	    vector<int> color(V, -1); 
	    for(int i=0;i<V;i++) {
	        if(color[i]==-1) {
	            if(!dfs(i,adj,color)){
                    return false;
                }  
	        }
	    }
	    return true; 
	}
};

void addEdge(vector<vector<int>>&adj,int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int main(){
    vector<vector<int>>adj(3);
    addEdge(adj,0,1);
    addEdge(adj,1,2);
    //Output =True
    Solution obj;
    cout<<obj.isBipartite(adj.size(), adj);
    return 0;
}