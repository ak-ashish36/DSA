//https://practice.geeksforgeeks.org/problems/eventual-safe-states/1
//https://leetcode.com/problems/find-eventual-safe-states/
//https://youtu.be/2gtg3VsDGyc
#include <bits/stdc++.h>
using namespace std;
//Safe states are the nodes which dont have cycle or leads to cycle
class Solution {
public:
    vector<int>eventualSafeNodesTopoSort(int N,vector<vector<int>>adj) {
        //Reverse the edges of graph and find indegree 
        vector<vector<int>>revAdj(N);
        vector<int>indegree(N,0);
        for(int i=0;i<N;i++){
            for(auto it :adj[i]){
                revAdj[it].push_back(i);
	            indegree[i]++; 
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
	        for(auto it : revAdj[node]) {
	            indegree[it]--;
	            if(indegree[it] == 0) {
	                q.push(it); 
	            }
	        }
	    }
        sort(ans.begin(),ans.end());
	    return ans;
	}
};
void addEdge(vector<vector<int>>&adj,int u,int v){
    adj[u].push_back(v);
}
int main(){
    vector<vector<int>>adj(7);
    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,1,2);
    addEdge(adj,1,3);
    addEdge(adj,2,5);
    addEdge(adj,3,0);
    addEdge(adj,4,5);
    //Output = {2,4,5,6}
    Solution obj;
    for(auto it :obj.eventualSafeNodesTopoSort(adj.size(),adj)){
        cout<<it<<" ";
    }
    return 0;
}