//https://youtu.be/3gbO7FDYNFQ
#include<bits/stdc++.h>
using namespace std;
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
    Set s1(6);
    s1.Union(4,5);
    cout<<s1.findPar(4)<<endl;
    cout<<s1.findPar(5)<<endl;;
    return 0;
}