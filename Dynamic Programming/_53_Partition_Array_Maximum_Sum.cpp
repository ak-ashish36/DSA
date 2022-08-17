//https://leetcode.com/problems/partition-array-for-maximum-sum/
//https://www.codingninjas.com/codestudio/problems/maximum-subarray_3755255
//https://youtu.be/PhWWJmaKfMc
#include <bits/stdc++.h>
using namespace std;
class Solution {
    int solve(int i,int n,int k,vector<int>& arr,vector<int>&dp){
        if(i==n){return 0;}
        if(dp[i]!=-1){return dp[i];}

        int maxSum=-1e9;
        int maxElement=-1e9;
        for(int j=i;j<min(i+k,n);j++){
            int len=j-i+1;//len++;
            maxElement = max(maxElement,arr[j]);
            int sum = len*maxElement + solve(j+1,n,k,arr,dp);
            maxSum=max(maxSum,sum);
        }
        return dp[i]=maxSum;
    }
public:
//Memoization
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n,-1);
        return solve(0,n,k,arr,dp);
    }
//Tabulation
    int maxSumAfterPartitioning2(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n+1,-1);
        dp[n]=0;

        for(int i=n-1;i>=0;i--){
            int maxSum=-1e9;
            int maxElement=-1e9;
            for(int j=i;j<min(i+k,n);j++){
                int len=j-i+1;//len++;
                maxElement = max(maxElement,arr[j]);
                int sum = len*maxElement + dp[j+1];
                maxSum=max(maxSum,sum);
            }
            dp[i]=maxSum;
        }
        return dp[0];
    }
};
int main(){
    vector<int>arr={1,15,7,9,2,5,10};
    int k=3;
    //Output = 84 ->[15,15,15,9,10,10,10]
    Solution obj;
    cout<<obj.maxSumAfterPartitioning2(arr,k);
    return 0;
}