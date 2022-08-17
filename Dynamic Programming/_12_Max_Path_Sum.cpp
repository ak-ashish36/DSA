//https://practice.geeksforgeeks.org/problems/path-in-matrix3805/1
//https://www.codingninjas.com/codestudio/problems/maximum-path-sum-in-the-matrix_797998/
//https://youtu.be/N_aJ5qQbYA0
#include<bits/stdc++.h>
using namespace std;
class Solution{
    int solve(int row,int col,vector<vector<int>> &matrix,vector<vector<int>>&dp){
        if(col<0 || col>=matrix[0].size()){return -1e9;}

        if(row==0){return matrix[0][col];}

        if(dp[row][col]!=-1){return dp[row][col];}

        int up = solve(row-1,col,matrix,dp);
        int l_diag = solve(row-1,col-1,matrix,dp);
        int r_diag =solve(row-1,col+1,matrix,dp);

        return dp[row][col]=matrix[row][col]+ max(up,max(l_diag,r_diag));
    }

public:
//Recursion T=O(m*(3^n)) S=O(n)   Memoization T=O(m*(n*m)) S=(n*m)+O(n)
    int getMaxPathSum(vector<vector<int>> &matrix){
        int row=matrix.size();
        int col=matrix[0].size();
        vector<vector<int>>dp(row,vector<int>(col,-1));
        int ans=-1e9;
        for(int i=col-1;i>=0;i--){
            ans=max(ans,solve(row-1,i,matrix,dp));
        }
        return ans;
    }
//Tabulation T=O(m*(n*m)) S=(n*m)
    int getMaxPathSum2(vector<vector<int>> &matrix){
        int row=matrix.size();
        int col=matrix[0].size();
        vector<vector<int>>dp(row,vector<int>(col,0));

        for(int j=0;j<col;j++){dp[0][j]=matrix[0][j];}

        for(int i=1;i<row;i++){
            for(int j=0;j<col;j++){
                int up=dp[i-1][j];
                int l_diag=-1e9,r_diag=-1e9;
                if(j>0)l_diag=dp[i-1][j-1];
                if(j<col-1)r_diag=dp[i-1][j+1];

                dp[i][j]=matrix[i][j]+ max(up,max(l_diag,r_diag));
            }
        }
        int ans=-1e9;
        for(int j=0;j<col;j++){
            ans=max(ans,dp[row-1][j]);
        }
        return ans;
    }

};
int main(){
    vector<vector<int>>matrix={{10,2,3},
                               {3,7,2},
                               {8,1,5}};
    //Output : 25
    Solution obj;
    cout<<obj.getMaxPathSum2(matrix);
    return 0;
}