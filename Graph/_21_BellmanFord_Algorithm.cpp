//https://youtu.be/75yC1vbS8S8
#include<bits/stdc++.h>
using namespace std;
struct node {
    int u;
    int v;
    int wt; 
    node(int first, int second, int weight) {
        u = first;
        v = second;
        wt = weight;
    }
};
class Solution{
    public:
    void shortestPath(int N, vector<node>&edges, int source){
        vector<int>dist(N,INT_MAX);
        dist[source]=0;

        for(int i = 1;i<=N-1;i++) {                 //Rank all the edges n-1 times
            for(auto it: edges) {
                if(dist[it.v] > dist[it.u] + it.wt) {
                    dist[it.v] = dist[it.u] + it.wt; 
                }
            }
        }
        int fl = 0; 
        for(auto it: edges) {
            if(dist[it.v] > dist[it.u] + it.wt) {
                cout << "Negative Cycle"; 
                fl = 1; 
                break; 
            }
        }

        if(!fl) {
            for(int i = 0;i<N;i++) {
                cout << i << " - " << dist[i] << endl;
            }
        }
    }

};
int main(){
    vector<node> edges; 
    edges.push_back(node(0,1,2));
	edges.push_back(node(0,3,6));
	edges.push_back(node(1,0,2));
	edges.push_back(node(1,2,3));
	edges.push_back(node(1,3,8));
	edges.push_back(node(1,4,5));
	edges.push_back(node(2,1,3));
	edges.push_back(node(2,4,7));
	edges.push_back(node(3,0,6));
	edges.push_back(node(3,1,8));
	edges.push_back(node(4,1,5));
	edges.push_back(node(4,2,7));

    Solution obj;
    obj.shortestPath(5,edges,0);
    return 0;
}