//https://leetcode.com/problems/cherry-pickup-ii/
//https://www.codingninjas.com/codestudio/problems/ninja-and-his-friends_3125885
//https://youtu.be/QGfn7JeXK54
#include<bits/stdc++.h>
using namespace std;
class Solution {
    int solve(int i, int j1, int j2,int row,int col,vector<vector<int>>& grid,vector<vector<vector<int>>>&dp){
        if(j1<0 || j1>col || j2>col || j2<0){return -1e8;}
        if(i==row){
            if(j1==j2){return grid[i][j1];}
            else{return grid[i][j1]+grid[i][j2];}
        }
        if(dp[i][j1][j2]!=-1){return dp[i][j1][j2];}
        int maxi=-1e8;
        for(int l=-1;l<=1;l++){
            for(int m=-1;m<=1;m++){
                int value=0;
                if(j1==j2){value=grid[i][j1];}
                else{value=grid[i][j1]+grid[i][j2];}
                maxi=max(maxi,value+solve(i+1,j1+l,j2+m,row,col,grid,dp));
            }
        }
        return dp[i][j1][j2]=maxi;
    }
public:
//Recursion T=O((3^n)*(3^n)) S=O(n)   Memoization T=O(n*m*m)) S=(n*m*m)+O(n)
    int cherryPickup(vector<vector<int>>& grid){
        int row=grid.size();
        int col =grid[0].size();
        vector<vector<vector<int>>>dp(row,vector<vector<int>>(col,vector<int>(col,-1)));

        return solve(0,0,col-1,row-1,col-1,grid,dp);
    }
};
int main(){
    vector<vector<int>>grid = {{3,1,1},
                               {2,5,1},
                               {1,5,5},
                               {2,1,1}};
    //Output : 24
    Solution obj;
    cout<<obj.cherryPickup(grid);                               
    return 0;
}