//https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
//https://youtu.be/V6H1qAeB-l4
#include <bits/stdc++.h>
using namespace std;
class Solution{
	public:
    //Time Complexity : O( E log(V) ) and Space Complexity : O( |E| + |V| )
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S){
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq;
        vector<int>dist(V,1e9);
        dist[S]=0;
        pq.push({0,S});
        while(!pq.empty()){
            int dis=pq.top().first;
            int node =pq.top().second;
            pq.pop();
            for(auto it :adj[node]){
                int adjNode = it[0];
                int wt = it[1];
                if(dis+wt < dist[adjNode]){
                    dist[adjNode] = dis+wt;
                    pq.push({dist[adjNode] , adjNode});
                }
            }
        }
        return dist;
    }
    //Using Set Data Structures
    vector <int> dijkstra2(int V, vector<vector<int>> adj[], int S){
        set<pair<int,int>>st;
        vector<int>dist(V,1e9);
        dist[S]=0;
        st.insert({0,S});
        while(!st.empty()){
            auto it=*(st.begin());
            int dis=it.first;
            int node =it.second;
            st.erase(it);
            for(auto it :adj[node]){
                int adjNode = it[0];
                int wt = it[1];
                if(dis+wt < dist[adjNode]){
                    dist[adjNode] = dis+wt;
                    st.insert({dist[adjNode] , adjNode});
                }
            }
        }
        return dist;
    }
};
int main(){
    int V=3,e=3;
    vector<vector<int>> adj[]={{{1, 1}, {2, 6}},
                                {{2, 3}, {0, 1}},
                                {{1, 3}, {0, 6}}};
    int src=2;
    //Output={4,3,0};
    Solution obj;
    for(int i :obj.dijkstra2(V,adj,src)){
        cout<<i<<" ";
    }
    return 0;
}