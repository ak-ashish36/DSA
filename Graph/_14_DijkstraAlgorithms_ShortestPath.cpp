#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> shortestPath(int V, vector<vector<pair<int,int>>>&adj, int source){
        
        vector<int>distance(V,INT_MAX);
        queue<pair<int,int>>q;
        q.push({source,0});

        distance[source]=0;

        while(!q.empty()){ 
            int node = q.front().first; 
		    q.pop();
		    for(auto it:adj[node]){
		        if(distance[it.first] > distance[node] + it.second){
		            distance[it.first]=distance[node]+it.second;
                    q.push({it.first,it.second});
		        }
		    }
        }
        return distance;
    }
};
void addEdge(vector<vector<pair<int,int>>>&adj,int u,int v,int wt){
    adj[u].push_back({v,wt});
    adj[v].push_back({u,wt});
}
int main(){
    vector<vector<pair<int,int>>>adj(6);
    addEdge(adj,1,2,2);
    addEdge(adj,1,4,1);

    addEdge(adj,2,5,5);
    addEdge(adj,2,3,4);

    addEdge(adj,3,4,3);
    addEdge(adj,3,5,1);
  
    Solution obj;
    vector<int>ans = obj.shortestPath(6,adj,1);
    for(int i : ans){
        cout<<i<<" ";
    }

    return 0;
}