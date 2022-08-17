//LIS Pattern of DP
//https://leetcode.com/problems/longest-increasing-subsequence/
//https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1
//https://www.codingninjas.com/codestudio/problems/longest-increasing-subsequence_630459/
//https://youtu.be/ekcwMsSIzVc
#include <bits/stdc++.h>
using namespace std;
class Solution {
    int solve(int i,int prev,vector<int>& nums,vector<vector<int>> &dp){
        // Base Case
        if(i == nums.size()){return 0;}

        // DP condition
        if(dp[i][prev+1] != -1){return dp[i][prev+1];}

        int take=0,notTake=0;
        // Not take 
        notTake = 0 + solve(i+1,prev,nums,dp);
       // Take if condition met and update previous
        if(prev == -1 || nums[i]>nums[prev]){
            take = 1+ solve(i+1,i,nums,dp);    
        }
        return dp[i][prev+1] = max(take,notTake);
    }
public: 
//Memoization   
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solve(0,-1,nums,dp);
    }
//Tabulation T= O(n2) S=O(n2) 
    int lengthOfLIS2(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));

        for(int i =n-1; i>=0;i--){
            for(int j =i-1; j>=-1;j--){         //Prev is always index-1
                int take=0,notTake=0;
                notTake= 0 + dp[i+1][j+1];
                if(j==-1 || nums[i]>nums[j]){
                    take = 1 + dp[i+1][i+1];
                }
                dp[i][j+1] = max(take,notTake); 
            }
        }
        return dp[0][0];
    }
//Algorithmic Approach T= O(n2) S=O(n)   
    int lengthOfLIS3(vector<int>& nums) {
        vector<int> dp(nums.size(),1);    // dp vector for storing length of increasing subsequence
        int maxi=1;
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp[i]=max(dp[i],dp[j]+1);     // updating the dp vector whenever nums[i] > nums[j]
                }
            }
            maxi=max(maxi,dp[i]);               // returning the longest increasing subsequence
        }
        return maxi;
    }
};
int main(){
    vector<int>arr={10,9,2,5,3,7,101,18};
    //Output = 4 {2,5,3,18};
    Solution obj; 
    cout<<obj.lengthOfLIS2(arr);
    return 0;
}