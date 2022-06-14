#include<bits/stdc++.h>
using namespace std;
void algo(vector<vector<int>>adj,vector<int>rulers,int curCity,int curRuler,int &count){
    for(auto it :adj[curCity]){
        if(rulers[it]!=curRuler){
            count++;
            algo(adj,rulers,it,rulers[it],count);
            break;
        }
    }
    return;
}
int sol(vector<vector<int>>adj,vector<int>rulers){
    int count=1;
    int source =1;
    int sourceRuler=rulers[1];
    algo(adj,rulers,source,sourceRuler,count);
    return count;
}
void addEdge(vector<vector<int>>&adj,int u,int v){
    adj[u].push_back(v);
}
int main(){
    vector<vector<int>>adj(7);
    vector<int>rulers={0,1,2,1,1,2,2};
    addEdge(adj,1,2);
    addEdge(adj,2,3);
    addEdge(adj,2,5);
    addEdge(adj,1,4);
    addEdge(adj,4,5);
    addEdge(adj,5,6);
    addEdge(adj,6,3);
    addEdge(adj,4,6);

    int ans=sol(adj,rulers);
    cout<<ans;
    //ans=3;
    return 0;
}