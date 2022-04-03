//https://youtu.be/HnD676J56ak
#include<bits/stdc++.h>
using namespace std;
//Time Complexity: O(N^2). Going through N Node for N-1 times
void mst(int N, vector<vector<pair<int,int>>>&adj){
    vector<int>parent(N,-1);
    vector<int>weight(N,INT_MAX);
    vector<bool>mstSet(N,false);

    weight[0]=0;

    for(int i=0; i< N-1; i++){
        int mini =INT_MAX;
        int u;
        for(int v=0; v<N;v++){                              //Finding the node which have minimum weight and it is not included in mst
            if(mstSet[v]==false && weight[v]<mini){
                mini=weight[v];
                u=v;
            }
        }
        mstSet[u]=true;                                       //After finding the minimum elem iclude it it mst

        for(auto it : adj[u]){
            int v = it.first;
            int wt =it.second;
            if(mstSet[v]==false && weight[v]>wt){
                weight[v] =wt;
                parent[v]=u;
            }
        }
    }

    for(int i=0;i<N;i++){
        cout<<parent[i]<<"->"<<i<<endl;
    }
}
//Time Complexity: O(NlogN). N iterations and logN for priority queue
void mst2(int N, vector<vector<pair<int,int>>>&adj){
    vector<int>parent(N,-1);
    vector<int>weight(N,INT_MAX);
    vector<bool>mstSet(N,false);

    weight[0]=0;
    priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq;         //{wieght,node}
    pq.push({0,0});

    for(int i=0; i< N-1; i++){
        int mini =INT_MAX;
        
        int u = pq.top().second;                            //Finding the node which have minimum weight and it is not included in mst
        pq.pop();

        mstSet[u]=true;                                       //After finding the minimum elem iclude it it mst

        for(auto it : adj[u]){
            int v = it.first;
            int wt =it.second;
            if(mstSet[v]==false && weight[v]>wt){
                pq.push({weight[v],v});
                weight[v] =wt;
                parent[v]=u;
            }
        }
    }

    for(int i=1;i<N;i++){
        cout<<parent[i]<<" - "<<i<<endl;
    }
}
void addEdge(vector<vector<pair<int,int>>>&adj,int u,int v,int wt){
    adj[u].push_back({v,wt});
    // adj[v].push_back({u,wt});
}
int main(){
    vector<vector<pair<int,int>>>adj(5);

    addEdge(adj,0,1,2);
    addEdge(adj,0,3,6);
    addEdge(adj,1,0,2);
    addEdge(adj,1,2,3);
    addEdge(adj,1,3,8);
    addEdge(adj,1,4,5);
    addEdge(adj,2,1,3);
    addEdge(adj,2,4,7);
    addEdge(adj,3,0,6);
    addEdge(adj,3,1,8);
    addEdge(adj,4,1,5);
    addEdge(adj,4,2,7);
  
    mst2(5,adj);

    return 0;
}