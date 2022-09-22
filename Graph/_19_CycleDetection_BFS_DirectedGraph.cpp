//https://youtu.be/V6GxfKDyLBM
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	bool topoSortCheck(int N,vector<vector<int>>adj) {
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
        int count=0;
	    while(!q.empty()) {
	        int node = q.front(); 
	        q.pop(); 
            count++;
	        for(auto it : adj[node]) {
	            indegree[it]--;
	            if(indegree[it] == 0) {
	                q.push(it); 
	            }
	        }
	    }
        if(count==N) return false;  // if toposort is generated it means grpah is acyclic
        return true;
	}
};
void addEdge(vector<vector<int>>&adj,int u,int v){
    adj[u].push_back(v);
}
int main(){
    vector<vector<int>>adj(5);
    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,1,0);
    addEdge(adj,1,3);
    addEdge(adj,2,3);
    addEdge(adj,2,4);
    //Output = True
    Solution obj;
    cout<<obj.topoSortCheck(5,adj);
 
}