//https://youtu.be/hwCWi7-bRfI
#include<bits/stdc++.h>
using namespace std;
vector<int> shortestPath(int V, vector<vector<int>>adj, int source){
    vector<int>distance(V,INT_MAX);

    distance[source]=0;
    queue<int>q;
    q.push(source);

    while(!q.empty()){
        int node = q.front(); 
		q.pop();
		for(auto it:adj[node]){
		    if( distance[it] > distance[node] + 1){
		        distance[it]=distance[node]+1;
		        q.push(it);
		    }
		} 
    }
    return distance;
}
void addEdge(vector<vector<int>>&adj,int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int main(){
    vector<vector<int>>adj(6);
    addEdge(adj,5,2);
    addEdge(adj,5,0);
    addEdge(adj,4,0);
    addEdge(adj,4,1);
    addEdge(adj,3,1);
    addEdge(adj,2,3);
    
    for(int i:shortestPath(6,adj,0)){
        cout<<i<<" ";
    }

    return 0;
}