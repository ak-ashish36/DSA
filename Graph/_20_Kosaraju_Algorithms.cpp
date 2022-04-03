//https://youtu.be/V8qIqJxCioo
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void findTopoSort(int node,vector<vector<int>>&adj, vector<int>& vis,stack<int>&s){ 
        vis[node] = 1; 
        for(auto it: adj[node]) {
            if(!vis[it]) {
                findTopoSort(it,adj,vis,s); 
            }
        }
        s.push(node);
    }
    void Dfs(int node, vector<int> &vis, vector<vector<int>>&transpose) {
        cout << node << " "; 
        vis[node] = 1; 
        for(auto it: transpose[node]) {
            if(!vis[it]) {
                Dfs(it, vis, transpose); 
            }
        }
    }
    void kosaraju(int n ,vector<vector<int>>&adj){
        stack<int> st;                              // Find topo sort
        vector<int> vis(n,0);
	    for(int i = 0;i<n;i++) {
	        if(vis[i]==0) {
	            findTopoSort(i,adj,vis,st); 
	        }
	    }

        vector<vector<int>>transpose(n);                   // Transpose graph  - reverse all the direction from u-v to v-u
        for(int i = 0;i<n;i++) {
	        vis[i] = 0; 
	        for(auto it: adj[i]) {
	        transpose[it].push_back(i); 
	        }
        }

	    while(!st.empty()) {                        //Find dfs of transpose graph accourting to topo sort
	        int node = st.top();
	        st.pop(); 
	        if(!vis[node]) {
	            cout << "SCC: "; 
	            Dfs(node, vis, transpose); 
	            cout << endl; 
	        }
	    }
    }
};
void addEdge(vector<vector<int>>&adj,int u,int v){
    adj[u].push_back(v);
}
int main(){
    vector<vector<int>>adj(6);
    addEdge(adj,5,5);
    addEdge(adj,0,1);
    addEdge(adj,1,2);
    addEdge(adj,2,0);
    addEdge(adj,1,3);
    addEdge(adj,3,4);
    Solution obj;
    obj.kosaraju(6,adj);
    return 0;
}