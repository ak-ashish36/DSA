//https://leetcode.com/problems/burst-balloons
//https://practice.geeksforgeeks.org/batch-problems/maximum-triple-product/1/
//https://www.codingninjas.com/codestudio/problems/mining-diamonds_4244494/
//https://youtu.be/Yz4LlDSlkns
#include <bits/stdc++.h>
using namespace std;
class Solution {
    int solve(int i , int j, vector<int>& nums,vector<vector<int>>&dp){
        if(i>j){return 0;}

        if(dp[i][j]!=-1){return dp[i][j];}

        int maxi=-1e9;

        for(int k=i;k<=j;k++){
            int coins = nums[i-1]*nums[k]*nums[j+1] + solve(i,k-1,nums,dp)+solve(k+1,j,nums,dp);
            maxi = max(coins,maxi);
        }
        return dp[i][j]=maxi;
    }
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(1,n,nums,dp);
    }

    int maxCoins2(vector<int>& nums) {
        int n=nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>>dp(n+2,vector<int>(n+2,0));

        for(int i=n;i>=1;i--){
            for(int j=1;j<=n;j++){
                if(i>j){continue;}
                int maxi=INT_MIN;
                for(int k=i;k<=j;k++){
                    int coins = nums[i-1]*nums[k]*nums[j+1] + dp[i][k-1]+dp[k+1][j];
                    maxi = max(coins,maxi);
                }
                dp[i][j]=maxi;
            }
        }
        return dp[1][n];
    }
};
int main(){
    vector<int>arr={3,1,5,8};
    //Output = 167
    Solution obj;
    cout<<obj.maxCoins2(arr);
    return 0;
}