//https://youtu.be/2rjZH0-2lhk
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    void dfs(int node, int parent, vector<int> &vis, vector<int> &tin, vector<int> &low, int &timer, vector<vector<int>>&adj) {
    vis[node] = 1; 
    tin[node] = low[node] = timer++; 
    for(auto it: adj[node]) {
        if(it == parent) continue;
        
        if(!vis[it]) {
            dfs(it, node, vis, tin, low, timer, adj); 
            low[node] = min(low[node], low[it]); 
            if(low[it] > tin[node]) {
                cout << node << " - " << it << endl;
            }
        } else {
            low[node] = min(low[node], tin[it]); 
        }
    }
    }
    void printBridge(int n, vector<vector<int>>&adj){
        vector<int> tin(n, -1);
	    vector<int> low(n, -1); 
	    vector<int> vis(n, 0); 
	    int timer = 0; 
	    for(int i = 0;i<n;i++) {
	        if(!vis[i]) {
	        dfs(i, -1, vis, tin, low, timer, adj); 
	        }
	    }
    }

};
void addEdge(vector<vector<int>>&adj,int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
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
    obj.printBridge(5,adj);
    return 0;
}