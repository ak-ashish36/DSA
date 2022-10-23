//https://practice.geeksforgeeks.org/problems/alien-dictionary/1
//https://leetcode.com/problems/alien-dictionary/
//https://youtu.be/U3N_je7tWAs
#include<bits/stdc++.h>
using namespace std;
class Solution{
    vector<int> topoSort(int N,vector<vector<int>>adj) {
	    vector<int> indegree(N, 0); 
	    for(int i=0;i<N;i++) {
	        for(auto it: adj[i]){
	            indegree[it]++; 
	        }
	    }
        queue<int> q; 
	    for(int i = 0;i<N;i++) {
	        if(indegree[i] == 0) {
	            q.push(i); 
	        }
	    }
	    vector<int> ans;
	    while(!q.empty()) {
	        int node = q.front(); 
	        q.pop(); 
	        ans.push_back(node);
	        for(auto it : adj[node]) {
	            indegree[it]--;
	            if(indegree[it] == 0) {
	                q.push(it); 
	            }
	        }
	    }
	    return ans;
	}
public:
    string findOrder(vector<string>dict, int N, int K){
        //Create adj matrix
        vector<vector<int>>adj(K);
        for(int i=0;i<N-1;i++){
            string word1=dict[i];
            string word2=dict[i+1];
            for(int j=0;j<min(word1.length(),word2.length());j++){
                if(word1[j]!=word2[j]){
                    adj[word1[j]-'a'].push_back(word2[j]-'a');
                    break;
                }
            }
        }
        //Find TopoSort
        vector<int>topo=topoSort(K,adj);
        string ans="";
        for(int i=0;i<topo.size();i++){
            ans+=char(topo[i]+'a');
        }
        return ans;
    }
};
int main(){
    int n=5,k=4;
    vector<string>dict = {"baa","abcd","abca","cab","cad"};
    //Output = bdac
    Solution obj;
    cout<<obj.findOrder(dict,n,k);
    return 0;
}