//https://leetcode.com/problems/course-schedule-ii/submissions/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //Create Graph
        vector<vector<int>> adj(numCourses);
        for(int i=0;i<prerequisites.size() ;i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        //Apply Topo Sort
        vector<int> indegree(numCourses, 0); 
	    for(int i=0;i<numCourses;i++) {
	        for(auto it: adj[i]){
	            indegree[it]++; 
	        }
	    }
        queue<int> q; 
	    for(int i =0;i<numCourses;i++) {
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
        if(ans.size()!=numCourses){ans.clear();}
	    return ans;
    }
};
int main(){
    vector<vector<int>>prerequisites = {{1,0},{2,0},{3,1},{3,2}};
    int numCourses=4;
    //Output= {0,1,2,3}
    Solution obj;
    for(int i :obj.findOrder(numCourses,prerequisites)){
        cout<<i<<" ";
    }
    return 0;
}