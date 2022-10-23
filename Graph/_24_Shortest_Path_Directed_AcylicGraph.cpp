//https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1
//https://youtu.be/ZUFQfFaU-8U
#include<bits/stdc++.h>
using namespace std;
class Solution{
    vector<int> topoSort(int N,vector<vector<pair<int,int>>>&adj) {
	    vector<int> indegree(N, 0); 
	    for(int i=0;i<N;i++) {
	        for(auto it: adj[i]){
	            indegree[it.first]++; 
	        }
	    }
        queue<int> q; 
	    for(int i = 0;i<N;i++) {
	        if(indegree[i] == 0) {
	            q.push(i); 
	        }
	    }
	    vector<int> ans;
	    while(!q.empty()) {
	        int node = q.front(); 
	        q.pop(); 
	        ans.push_back(node);
	        for(auto it : adj[node]) {
	            indegree[it.first]--;
	            if(indegree[it.first] == 0) {
	                q.push(it.first); 
	            }
	        }
	    }
	    return ans;
	}
public:
    vector<int> shortestPath(int N,int M, vector<vector<int>>& edges,int source=0){
        //First Convert the edges into adjacency list
        vector<vector<pair<int,int>>>adj(N);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        vector<int>topo=topoSort(N,adj);
        vector<int>dist(N,1e9);
        dist[source]=0;
        for(int node : topo){
            for(auto it :adj[node]){
                int v = it.first;
                int wt = it.second;
                if(dist[node]+wt < dist[v]){
                    dist[v] = dist[node]+wt;
                }
            }
        }
        for(int i=0;i<N;i++){
            if(dist[i]==1e9){
                dist[i]=-1;
            }
        }
        return dist;
    }
};
int main(){
    int n=6,m=7;
    vector<vector<int>>edges={{0,1,2},{0,4,1},{4,5,4},{4,2,2},{1,2,3},{2,3,6},{5,3,1}};
    int src=0;
    //Output = {0,2,3,6,1,5}
    Solution obj;
    for(int i : obj.shortestPath(n,m,edges,src)){
        cout<<i<<" ";
    }
    return 0;
}