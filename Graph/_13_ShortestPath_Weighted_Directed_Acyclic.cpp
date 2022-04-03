//https://youtu.be/CrxG4WJotgg
#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    void findTopoSort(int node, vector<vector<pair<int,int>>>&adj, vector<int>& vis,stack<int>&s){ 
        vis[node] = 1; 
        for(auto it: adj[node]) {
            if(!vis[it.first]) {
                findTopoSort(it.first,adj,vis,s); 
            }
        }
        s.push(node);
    }
    void topoSort(int V,  vector<vector<pair<int,int>>>&adj,stack<int>&s) {
        vector<int> vis(V,0);
	    for(int i = 0;i<V;i++) {
	        if(vis[i]==0) {
	            findTopoSort(i,adj,vis,s); 
	        }
	    }
    }
public:
    vector<int> shortestPath(int V, vector<vector<pair<int,int>>>&adj, int source){
    
        stack<int>s;
        topoSort(V,adj,s);

        vector<int>distance(V,INT_MAX);

        distance[source]=0;

        while(!s.empty()){
            int node = s.top(); 
		    s.pop();
            if(distance[node]!=INT_MAX){
		    for(auto it:adj[node]){
		        if(distance[it.first] > distance[node] + it.second){
		            distance[it.first]=distance[node]+it.second;
		        }
		    }
            }
        }
        return distance;
    }
};
void addEdge(vector<vector<pair<int,int>>>&adj,int u,int v,int wt){
    adj[u].push_back({v,wt});
}
int main(){
    vector<vector<pair<int,int>>>adj(8);
    addEdge(adj,0,1,2);
    addEdge(adj,0,4,1);
    addEdge(adj,1,2,3);
    addEdge(adj,2,3,6);
    addEdge(adj,4,2,2);
    addEdge(adj,4,5,4);
    addEdge(adj,5,3,1);

    addEdge(adj,6,7,2); // infinte path

    Solution obj;
    vector<int>ans = obj.shortestPath(8,adj,0);
    for(int i : ans){
        cout<<i<<" ";
    }

    return 0;
}