//https://leetcode.com/problems/unique-paths/
#include<bits/stdc++.h>
using namespace std;

int uniquePaths(int m,int n,int i=0,int j=0) {
        if(i==m-1 && j==n-1){return 1;}
        else if(i>=m || j>=n){return 0;}
        else{
            return uniquePaths(m,n,i+1,j)+uniquePaths(m,n,i,j+1);
        }
}
// Using Dynamic Programming T=O(nm), S=O(nm)
int countPaths(int i,int j,int n,int m,vector<vector<int>>&dp) {
        if(i==m-1 && j==n-1){return 1;}
        else if(i>=m || j>=n){return 0;}
        else if(dp[i][j]!=-1){return dp[i][j];}
        else{
            return dp[i][j]=countPaths(i+1,j,n,m,dp)+countPaths(i,j+1,n,m,dp);
        }
}

int uniquePaths2(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        //dp[1][1]=1;
       int num=countPaths(0,0,m,n,dp);
        if(m==1&&n==1)
            return num;
        return dp[0][0];
}
//Best approach T=O(m-1) or O(n-1) and S=O(1)
int uniquePaths3(int m, int n) {
            int N = n + m - 2;
            int r = m - 1; 
            double res = 1;
            //Find nCr
            for (int i = 1; i <= r; i++)
                res = res * (N - r + i) / i;
            return (int)res;
}

int main(){
    cout<<uniquePaths3(3,3);
    return 0;
}
