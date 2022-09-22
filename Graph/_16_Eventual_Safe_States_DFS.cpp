//https://practice.geeksforgeeks.org/problems/eventual-safe-states/1
//https://leetcode.com/problems/find-eventual-safe-states/
//https://youtu.be/uRbJ1OF9aYM
#include <bits/stdc++.h>
using namespace std;
//Safe states are the nodes which dont have cycle or leads to cycle
class Solution {
    bool checkForCycle(int node,vector<vector<int>>&adj,vector<int>& vis,vector<int>&pathVis,vector<int>&check){ 
        vis[node] = 1; 
        pathVis[node]=1;
        check[node]=0;
        for(auto it: adj[node]){
            if(!vis[it]) {
                if(checkForCycle(it,adj,vis,pathVis,check)){
                    check[node]=0;
                    return true;
                }
            }
            else if(pathVis[it]){
                check[node]=0;
                return true; 
            }
        }
        check[node]=1;
        pathVis[node]=0;
        return false; 
    }
public:
    vector<int> eventualSafeNodes(int V,vector<vector<int>>&adj) {
        vector<int> vis(V, 0);
        vector<int> pathVis(V, 0);
        vector<int>check(V,0);
	    for(int i = 0;i<V;i++) {
	        if(!vis[i]) {
	            checkForCycle(i,adj,vis,pathVis,check);
	        }
	    }
        vector<int>ans;
        for(int i=0;i<V;i++){
            if(check[i]==1){ans.push_back(i);}
        }
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
    for(auto it :obj.eventualSafeNodes(adj.size(),adj)){
        cout<<it<<" ";
    }
    return 0;
}