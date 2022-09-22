//https://practice.geeksforgeeks.org/problems/topological-sort/1
//https://youtu.be/Yh6EFazXipA
//Toposort means in (u->v) u appears before v in all case . it can be only possilbe in  Directed Acylic Graph
#include<bits/stdc++.h>
using namespace std;
class Solution {
    void dfs(int node,vector<vector<int>>&adj, vector<int>& vis,stack<int>&s){ 
        vis[node] = 1; 
        for(auto it: adj[node]) {
            if(!vis[it]) {
                dfs(it,adj,vis,s); 
            }
        }
        s.push(node);
    }
public:
    vector<int> topoSort(int V, vector<vector<int>>&adj) {
        vector<int> vis(V,0);
        stack<int>s;
	    for(int i = 0;i<V;i++) {
	        if(vis[i]==0) {
	            dfs(i,adj,vis,s); 
	        }
	    }
        vector<int>ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};
void addEdge(vector<vector<int>>&adj,int u,int v){
    adj[u].push_back(v);
}
int main(){
    vector<vector<int>>adj(6);
    addEdge(adj,5,2);
    addEdge(adj,5,0);
    addEdge(adj,4,0);
    addEdge(adj,4,1);
    addEdge(adj,3,1);
    addEdge(adj,2,3);
    //Output = {5,4,2,3,1,0}
    Solution obj;
    vector<int>ans = obj.topoSort(6,adj);
    for(int i : ans){
        cout<<i<<" ";
    }
    return 0;
}