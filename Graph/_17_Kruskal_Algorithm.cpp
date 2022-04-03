//https://youtu.be/1KRmCzBl_mQ
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
bool comp(node a, node b) {
    return a.wt < b.wt; 
}
class Set{
    private:
        vector<int> parent;
	    vector<int> rank;
    public:
        Set(int N){
            parent.resize(N);
	        for(int i = 0;i<N;i++) 
	            parent[i] = i; 
	        rank.resize(N, 0);
        }
        int findPar(int u) {
            if(parent[u] == u) return u; 
            return parent[u] = findPar(parent[u]); 
        }
        void Union(int u, int v) {
            u = findPar(u);
            v = findPar(v);
            if(rank[u] < rank[v]) {
    	        parent[u] = v;
            }
            else if(rank[v] < rank[u]) {
    	        parent[v] = u; 
            } 
            else {
    	        parent[v] = u;
    	        rank[u]++; 
            }
        } 
};
int main(){
    int N=5;
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
	sort(edges.begin(), edges.end(), comp);             //for this algo all the edges must be sorted w.r.t weight

    Set s1(N);
    int cost = 0;
	vector<pair<int,int>> mst;
    for(auto it : edges) {
	    if(s1.findPar(it.u) != s1.findPar(it.v)) {
	        cost += it.wt; 
	        mst.push_back({it.u, it.v}); 
	        s1.Union(it.u, it.v); 
	    }
	}
    cout << cost << endl;
	for(auto it : mst) cout << it.first << " - " << it.second << endl;  
    return 0;
}