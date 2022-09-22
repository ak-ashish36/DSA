//https://practice.geeksforgeeks.org/problems/number-of-enclaves/1
//https://leetcode.com/problems/number-of-enclaves/
//https://youtu.be/rxKcepXQgU4
#include <bits/stdc++.h>
using namespace std;
class Solution {
    void dfs(int i,int j ,vector<vector<int>>& grid,vector<vector<int>>& visited){
        if(i>=grid.size() || j>=grid[0].size() || i<0 || j<0){return;}
        if(visited[i][j]==1 || grid[i][j]==0){return ;}
        
        visited[i][j]=1;
        
        dfs(i-1,j,grid,visited); //checkLeft
        dfs(i+1,j,grid,visited); //checkRight
        dfs(i,j-1,grid,visited); //checkUp
        dfs(i,j+1,grid,visited); //checkDown
    }
    void bfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& visited){
        int n=grid.size();
        int m=grid[0].size();
        visited[i][j]=1;
        queue<pair<int,int>>q;
        q.push({i,j});
        int delRow[]={-1,1,0,0};
        int delCol[]={0,0,-1,1};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int nR=row+delRow[k];
                int nC=col+delCol[k];
                if(nR>=0 && nC>=0 && nR<n && nC<m && !visited[nR][nC] && grid[nR][nC]==1){
                    visited[nR][nC]=1;
                    q.push({nR,nC});
                }

            }
        }
    }
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        int count=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || i==n-1 || j==0 || j==m-1){//Check only 'O' at all 4 boundary
                    if(!visited[i][j] && grid[i][j]==1){
                        bfs(i,j,grid,visited);
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]==1){
                    count++;
                }
            }
        }
        return count;
    }
};
int main(){
    vector<vector<int>>grid={{0, 0, 0, 0},
                            {1, 0, 1, 0},
                            {0, 1, 1, 0},
                            {0, 0, 0, 0}};
    //Output = 3
    Solution obj;
    cout<<obj.numberOfEnclaves(grid);
    return 0;
}