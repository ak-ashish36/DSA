//https://leetcode.com/problems/triangle/
//https://youtu.be/SrP-PiLSYC0
#include<bits/stdc++.h>
using namespace std;
class Solution {
    int solve(vector<vector<int>>& triangle,int i,int j,int row,int col,vector<vector<int>>&dp){

        if(i==row && j<=col){
            return triangle[row][j];
        }
        if(i>row || j>col){
            return 0;
        }
        if(dp[i][j]!=-1){return dp[i][j];}
        int down = solve(triangle,i+1,j,row,col+1,dp);
        int diag =solve(triangle,i+1,j+1,row,col+1,dp);
        
        return dp[i][j]= triangle[i][j] + min(down,diag);
    }
public:
    //Recursion -> T= O(2^(1+2+..n)) S=O(n) ||  Memoization-> T=O(n*n) S=O(n*n)+O(n)
    int minimumTotal(vector<vector<int>>& triangle) {
        int row=triangle.size();
        vector<vector<int>>dp(row,vector<int>(row,-1));
        return solve(triangle,0,0,row-1,0,dp);
    }
    //Tabulation T=O(n*n) S=O(n*n)
    int minimumTotal2(vector<vector<int>>& triangle) {
        int row=triangle.size();
        vector<vector<int>>dp(row,vector<int>(row,0));
        //Base Case
        for(int j=0;j<row;j++){
            dp[row-1][j]=triangle[row-1][j];
        }
        for(int i=row-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int down=dp[i+1][j];
                int diag=dp[i+1][j+1];

                dp[i][j]=triangle[i][j]+min(down,diag);
            }
        }
        return dp[0][0];
    }
    //Space Optimization T=O(n*n) S=O(2n)
    int minimumTotal3(vector<vector<int>>& triangle) {
        int row=triangle.size();
        vector<int>prev(row,0),curr(row,0);
        //Base Case
        for(int j=0;j<row;j++){
            prev[j]=triangle[row-1][j];
        }
        for(int i=row-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int down=prev[j];
                int diag=prev[j+1];

                curr[j]=triangle[i][j]+min(down,diag);
            }
            prev=curr;
        }
        return prev[0];
    }
};
int main(){
    vector<vector<int>>triangle={{2},
                                 {3,4},
                                 {6,5,7},
                                 {4,1,8,3}};
    Solution obj;
    cout<<obj.minimumTotal3(triangle);                                 
    return 0;
}