//https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1
//https://youtu.be/C4gxoTaI71U
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>&edges, int N,int M, int src){
        //First Convert the edges into adjacency list
        vector<vector<int>>adj(N);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>dist(N,1e9);
        dist[src]=0;
        queue<int>q;
        q.push(src);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it :adj[node]){
                if(dist[node]+1 < dist[it]){
                    dist[it] = dist[node]+1;
                    q.push(it);
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
    vector<vector<int>>edges={{0,1},{0,4},{4,5},{4,2},{1,2},{2,3},{5,3}};
    int src=4;
    //Output = {1,2,1,2,0,1}
    Solution obj;
    for(int i : obj.shortestPath(edges,n,m,src)){
        cout<<i<<" ";
    }
    return 0;
}