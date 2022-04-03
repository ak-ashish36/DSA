//https://youtu.be/nbgaEu-pvkU
// Graph that can  be colored with two colors such that no two adjacent node have same color
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool bipartiteBfs(int s,vector<vector<int>>&adj, vector<int>& color){ 
        // Create a queue for BFS
        queue<int> q;
     
        color[s] = 1;
        q.push(s);
     
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto it : adj[node]) {
                if (color[it]==-1) {
                    color[it] = 1-color[node] ;
                    q.push(it);
                }
                else if (color[it] == color[node]){       //
                    return false;
                }
            }
        }
        return true;
    }
public:
	bool isBipartite(int V,vector<vector<int>>&adj){
	    vector<int> color(V, -1); 
	    for(int i = 0;i<V;i++) {
	        if(color[i]==-1) {
	            if(!bipartiteBfs(i,adj,color)){
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
    vector<vector<int>>adj(8);
   
    // addEdge(adj,8,7);
    // addEdge(adj,0,1);
    // addEdge(adj,1,2);
    // addEdge(adj,2,3);
    // addEdge(adj,3,4);
    // addEdge(adj,4,6);
    // addEdge(adj,6,7);
    // addEdge(adj,1,7);
    // addEdge(adj,4,5);

    addEdge(adj,7,7);
    addEdge(adj,0,1);
    addEdge(adj,1,2);
    addEdge(adj,2,3);
    addEdge(adj,3,4);
    addEdge(adj,4,6);
    addEdge(adj,6,1);
    addEdge(adj,4,5);


    Solution obj;
    cout<<obj.isBipartite(8, adj);
 
    return 0;
}