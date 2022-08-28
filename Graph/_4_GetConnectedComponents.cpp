//https://youtu.be/UeE67iCK2lQ
#include <bits/stdc++.h>

using namespace std;
class Solution {
  public:
    void dfs(int node,vector<vector<int>>&adj, vector<int>&vis, vector<int>&ans) {
        ans.push_back(node); 
        vis[node] = 1; 
        for(auto it : adj[node]) {
            if(!vis[it]) {
                dfs(it,adj,vis,ans); 
            }
        }
    }

    vector<vector<int>> dfsOfGraph(int V,vector<vector<int>>&adj){
	    vector<vector<int>>final_ans;
	    vector<int> ans;
	    vector<int> vis(V, 0); 
        for(int i=0;i<V;i++) {
            if(!vis[i]){
                dfs(i, adj,vis,ans);
            }
            if(ans.size()>0){
                final_ans.push_back(ans);
                ans.clear();
            }
        }
	    return final_ans;
	}
};

void addEdge(vector<vector<int>>&adj, int u, int v) {
  adj[u].push_back(v);
  adj[v].push_back(u);
}

int main(){
    vector<vector<int>> adj(7);
    addEdge(adj,0,1);
    addEdge(adj,2,3);
    addEdge(adj,4,5);
    addEdge(adj,5,6);
    addEdge(adj,4,6);
    
    Solution obj;
    vector<vector<int>> ans;
    ans= obj.dfsOfGraph(7, adj);
    cout<<"[";
    for(int i=0;i<ans.size();i++){
        cout<<"{";
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<",";
        }
        cout<<"}";
    }
    cout<<"]";
 
    return 0;
}