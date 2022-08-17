//Dp on Partition
//https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1
//https://www.codingninjas.com/codestudio/problems/matrix-chain-multiplication_975344/
//https://youtu.be/vRVfmbCFW7Y
#include <bits/stdc++.h>
using namespace std;
class Solution{
    int solve(int i,int j,vector<int>arr,vector<vector<int>>&dp){
        if(i==j){return 0;}
        if(dp[i][j]!=-1){return dp[i][j];}
        int mini=1e9;
        for(int k=i;k<j;k++){
            int steps = arr[i-1]*arr[k]*arr[j] + solve(i,k,arr,dp)+solve(k+1,j,arr,dp);
            mini =min(mini,steps);
        }
        return dp[i][j]=mini;
    }
public:
    int matrixMultiplication(vector<int>arr){
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(1,n-1,arr,dp);
    }
//Tabulation
    int matrixMultiplication2(vector<int>arr){
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=1;i<n;i++){dp[i][i]=0;}
        for(int i=n-1;i>=1;i--){
            for(int j=i+1;j<n;j++){
                int mini =1e9;
                for(int k=i;k<j;k++){
                    int steps =arr[i-1]*arr[k]*arr[j] + dp[i][k]+dp[k+1][j];
                    mini=min(mini,steps);
                }
                dp[i][j]=mini; 
            }
        }
        return dp[1][n-1];
    }
};
int main(){
    vector<int>arr={40, 20, 30, 10, 30}; 
    // Output = 26000
    Solution obj;
    cout<<obj.matrixMultiplication2(arr);
    return 0;
}