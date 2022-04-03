#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, m;       // n =no of nodes , m=number of edges
	cin >> n >> m; 
	
	// declare the adjacent matrix 
	vector<vector<int>>adj(n+1);
	
	// take edges as input 
	for(int i = 0;i<m;i++) {
	    int u, v;                       // node u is connecting to node v
	    cin >> u >> v;
	    adj[u].push_back(v); 
	    adj[v].push_back(u); 
	}
	return 0;
} 