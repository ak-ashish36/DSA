//https://leetcode.com/problems/number-of-provinces/
//https://practice.geeksforgeeks.org/problems/number-of-provinces/1
//https://youtu.be/ACzkVtewUYA
#include <bits/stdc++.h>
using namespace std;
class Solution {
    void dfs(int node,vector<vector<int>> adj,vector<int>&visited){
        visited[node]=1;
        for(auto it :adj[node]){
            if(!visited[it]){
                dfs(it,adj,visited);
            }
        }
    }
public:
//T = O(n)+O(V+2E)      S=O(N)+O(N)
    int numProvinces(vector<vector<int>>&adj) {
        int V =adj.size();
        vector<vector<int>> graph(V);
        //Convert 2d Matrix in form of graph
        for(int i=0;i<V;i++){
           for(int j=0;j<V;j++){
              if(i==j)continue;
              else if(adj[i][j]==1 && adj[j][i]==1){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
              }
           }
        }
        
        vector<int>visited(V,0);
        int count =0;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i,graph,visited);
                count++;
            }
        }  
        return count;
    }
};
int main(){
    vector<vector<int>>adj={{1,1,0},
                            {1,1,0},
                            {0,0,1}};
    //Output = 2 components  1->2 and 3 
    Solution obj;
    cout<<obj.numProvinces(adj);
    return 0;
}