//https://www.codingninjas.com/codestudio/problems/total-unique-paths_1081470
//https://leetcode.com/problems/unique-paths/submissions/
//https://youtu.be/sdE0A2Oxofw
#include<bits/stdc++.h>
using namespace std;
class Solution{
    int sol(int i, int j, int rows,int cols,vector<vector<int>>&dp){
        if(i==rows && j==cols){return 1;}
        if(i>rows|| j>cols){return 0;}

        if(dp[i][j]!=-1){return dp[i][j];}

        int right = sol(i,j+1,rows,cols,dp);
        int down = sol(i+1,j,rows,cols,dp);

        return dp[i][j]=right+down;
    }
    int sol2(int row,int col,vector<vector<int>>&dp){    
        if(row==0 && col==0){return 1;}
        if(row<0 || col<0){return 0;}

        if(dp[row][col]!=-1){return dp[row][col];}

        int left=sol2(row,col-1,dp);
        int up = sol2(row-1,col,dp);

        return dp[row][col]=left+up;
    }
public:
    // Memoization T=O(nm), S=O(nm)+O((n-1)+(m-1)) Stack Space
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        // return sol(0,0,m-1,n-1,dp);
        return sol2(m-1,n-1,dp);
    }

    // Tabulation T=O(nm), S=O(nm)          
    int uniquePaths2(int m,int n){
        vector<vector<int>>dp(m,vector<int>(n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 & j==0){dp[i][j]=1;}
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
    // Tabulation Space Optimization T=O(nm), S=O(2n)          
    int uniquePaths3(int m,int n){

        vector<int>prev(n,0);

        for(int i=0;i<m;i++){
            vector<int>curr(n,0);
            for(int j=0;j<n;j++){
                if(i==0 & j==0){curr[j]=1;}
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
    //Output : 6
    Solution obj;
    cout<<obj.uniquePaths3(3,3);
    return 0;
}