//https://leetcode.com/problems/course-schedule/
//https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //Create Graph in Proper Order
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
        int count=0;    //Count no of courses
	    while(!q.empty()) {
	        int node = q.front(); 
	        q.pop(); 
	        count++;
	        for(auto it : adj[node]) {
	            indegree[it]--;
	            if(indegree[it] == 0) {
	                q.push(it); 
	            }
	        }
	    }
        if(count!=numCourses){return false;}
	    return true;
    }
};
int main(){
    vector<vector<int>>prerequisites = {{1,0},{0,1}};
    int numCourses=4;
    //Output= False
    Solution obj;
    cout<<obj.canFinish(numCourses,prerequisites);
    return 0;
}