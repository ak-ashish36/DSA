//https://leetcode.com/problems/unique-paths-ii/
//https://www.codingninjas.com/codestudio/problems/maze-obstacles_977241/
//https://youtu.be/TmhpgXScLyY
#include<bits/stdc++.h>
using namespace std;
class Solution{
    int sol(vector<vector<int>>& obstacleGrid,int row,int col,vector<vector<int>>&dp){    

        if(row>=0 && col>=0 && obstacleGrid[row][col]==1){return 0;}

        if(row==0 && col==0){return 1;}
        if(row<0 || col<0){return 0;}

        
        if(dp[row][col]!=-1){return dp[row][col];}

        int left=sol(obstacleGrid,row,col-1,dp);
        int up = sol(obstacleGrid,row-1,col,dp);
        
        return dp[row][col]=left+up;
    }
public:
    // Memoization T=O(nm), S=O(nm)+O((n-1)+(m-1)) Stack Space
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid){
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return sol(obstacleGrid,m-1,n-1,dp);
    }
    // Tabulation T=O(nm), S=O(nm)          
    int uniquePathsWithObstacles2(vector<vector<int>>& obstacleGrid){
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(obstacleGrid[i][j]==1){dp[i][j]=0;}
                else if(i==0 && j==0){dp[i][j]=1;}
                else{
                    int left=0,up=0;
                    if(i>0) up=dp[i-1][j];
                    if(j>0) left=dp[i][j-1];
                    dp[i][j]= up+left;
                }
            }
        }
        return dp[m-1][n-1];
    }
    // Tabulation Space Optimization  T=O(nm), S=O(2n)          
    int uniquePathsWithObstacles3(vector<vector<int>>& obstacleGrid){
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<int>prev(n,0);

        for(int i=0;i<m;i++){
            vector<int>curr(n,0);
            for(int j=0;j<n;j++){
                if(obstacleGrid[i][j]==1){curr[j]=0;}
                else if(i==0 && j==0){curr[j]=1;}
                else{
                    int left=0,up=0;
                    if(i>0) up=prev[j];
                    if(j>0) left=curr[j-1];
                    curr[j]= up+left;
                }
            }
            prev=curr;
        }
        return prev[n-1];
    }

};

int main(){
    vector<vector<int>>obstacleGrid = {{0,0,0},
                                       {0,1,0},
                                       {0,0,0}};
    //Output : 2
    Solution obj;
    cout<<obj.uniquePathsWithObstacles2(obstacleGrid);
    return 0;
}