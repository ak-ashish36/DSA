//https://youtu.be/rZv_jHZva34
// toposort means in (u->v) u appears before v in all case . it can be only possilbe in  Directed Acylic Graph
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	vector<int> topoSort(int N,vector<vector<int>>adj) {
        // Create indegree vector to marks degree of all nodes
	    vector<int> indegree(N, 0); 
	    for(int i = 0;i<N;i++) {
	        for(auto it: adj[i]) {
	            indegree[it]++; 
	        }
	    }
        //Start now
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
	            indegree[it]--;
	            if(indegree[it] == 0) {
	                q.push(it); 
	            }
	        }
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

    Solution obj;
    vector<int>ans = obj.topoSort(6,adj);
    for(int i : ans){
        cout<<i<<" ";
    }
}