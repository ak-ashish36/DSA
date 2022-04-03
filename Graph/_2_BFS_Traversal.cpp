//https://youtu.be/UeE67iCK2lQ
#include <bits/stdc++.h>

using namespace std;
class Solution {
  public:
    void bfs(int V, vector<vector<int>> adj, vector<int>&vis, vector<int>&ans) {
      queue < int > q;
      q.push(0);
      vis[0] = 1;

      while (!q.empty()) {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        // for(int i =0;i<adj[node].size();i++){
        //     if(!vis[adj[node][i]]){
        //         q.push(adj[node][i]);
        //         vis[adj[node][i]]=1;
        //     }
        // }
        for (auto it: adj[node]) {
          if (!vis[it]) {
            q.push(it);
            vis[it] = 1;
          }
        } 
      }
    }

    vector<int>bfsOfGraph(int V,vector<vector<int>> adj){
	    vector<int> ans; 
	    vector<int> vis(V+1, 0); 
        for(int i=0;i<V;i++) {
            if(!vis[i]) bfs(i, adj,vis,ans); 
        }
	    return ans; 
	}
};

void addEdge(vector<vector<int>>&adj, int u, int v) {
  adj[u].push_back(v);
  adj[v].push_back(u);
}

int main() {
   
  vector<vector<int>> adj(5);

  addEdge(adj, 0, 1);
  addEdge(adj, 0, 2);
  addEdge(adj, 0, 3);
  addEdge(adj, 2, 4);

  Solution obj;
  vector < int > ans = obj.bfsOfGraph(5, adj);
  for(int i:ans){
      cout<<i<<" ";
  }

  return 0;
}