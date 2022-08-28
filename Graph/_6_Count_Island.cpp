//https://leetcode.com/problems/number-of-islands/
//https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1
//https://youtu.be/muncqlKJrH0
#include <bits/stdc++.h>
using namespace std;
class Solution {
    void bfs(int i,int j,vector<vector<char>>& grid,vector<vector<int>>&visited){
        visited[i][j]=1;
        queue<pair<int,int>>q;
        q.push({i,j});

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int delRow=-1;delRow<=1;delRow++){  //check in all 8 directions
                for(int delCol=-1;delCol<=1;delCol++){
                    int nRow = row + delRow;
                    int nCol = col +delCol;
                    if(nRow>=grid.size() || nCol>=grid[0].size() || nRow<0 || nCol<0){continue;}
                    if(grid[nRow][nCol]=='0' || visited[nRow][nCol]==1){continue;}
                    visited[nRow][nCol]=1;
                    q.push({nRow,nCol});
                }
            }
        }
    }
    void dfs(int i,int j,vector<vector<char>>& grid,vector<vector<int>>&visited){
        if(i>=grid.size() || j>=grid[0].size() || i<0 || j<0){return;}
        if(grid[i][j]=='0' || visited[i][j]==1){return ;}
        visited[i][j]=1;

        dfs(i-1,j,grid,visited); //checkLeft
        dfs(i+1,j,grid,visited); //checkRight
        dfs(i,j-1,grid,visited); //checkUp
        dfs(i,j+1,grid,visited); //checkDown
        // dfs(i-1,j-1,grid,visited); //check_LU_diag
        // dfs(i+1,j-1,grid,visited); //check_RU_diag
        // dfs(i+1,j+1,grid,visited); //check_RD_diag
        // dfs(i-1,j+1,grid,visited); //check_LD_diag
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        int count=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    dfs(i,j,grid,visited);
                    count++;
                }
            }
        }
        return count;
    }
};
int main(){
    vector<vector<char>>grid = {{'1','1','0'},
                                {'1','1','0'},
                                {'0','0','1'}};
    //Output = 2
    Solution obj;
    cout<<obj.numIslands(grid);
    return 0;
}