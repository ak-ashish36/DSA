//https://leetcode.com/problems/minimum-path-sum/
//https://youtu.be/_rgTlyky1uQ
#include<bits/stdc++.h>
using namespace std;
class Solution {
    int sol(int row,int col,vector<vector<int>>& grid,vector<vector<int>>&dp){
        if(row==0 && col ==0){return grid[row][col];}

        if(row<0 || col <0){return INT_MAX;}

        if(dp[row][col]!=-1){return dp[row][col];}

        int left = sol(row,col-1,grid,dp);
        int up = sol(row-1,col,grid,dp);

        return dp[row][col]=grid[row][col]+min(left,up);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row=grid.size();
        int col =grid[0].size();
        vector<vector<int>>dp(row,vector<int>(col,-1));
        return sol(row-1,col-1,grid,dp);
    }

    int minPathSum2(vector<vector<int>>& grid){
        int row=grid.size();
        int col =grid[0].size();
        vector<vector<int>>dp(row,vector<int>(col,0));

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(i==0 && j==0){dp[i][j]=grid[i][j];}
                else{
                    int left=INT_MAX,up=1e9;
                    if(i>0)up=dp[i-1][j];
                    if(j>0)left=dp[i][j-1];

                    dp[i][j]=grid[i][j]+min(left,up);
                }
            }
        }

        return dp[row-1][col-1];
    }
    
};
int main(){
    vector<vector<int>> grid ={{1,3,1},
                               {1,5,1},
                               {4,2,1}};
    //Output : 7
    Solution obj;
    cout<<obj.minPathSum2(grid);                               
    return 0;
}