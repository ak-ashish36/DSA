//https://leetcode.com/problems/house-robber/
//https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1
//https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261/
//https://youtu.be/GrMBfJNk_NY
#include<bits/stdc++.h>
using namespace std;
class Solution{
    int sol(int n,vector<int>& nums, vector<int>&dp){
        if(n==0){return nums[n];}
        if(n<0){return 0;}
        if(dp[n]!=-1){return dp[n];}
        
        int pick = nums[n]+sol(n-2,nums,dp);
        int notpick =sol(n-1,nums,dp);
        
        return dp[n]=max(pick,notpick);
    }
public:
    // Recursion T=(2^n) + Memoization   T=O(n)   S=O(n)+O(n) (Stack space + dp arr)
    int rob(vector<int>& nums) {
        int n= nums.size();
        vector<int>dp(n,-1);
        return sol(n-1, nums, dp);
    }
    // Tabulation
    int rob2(vector<int>&nums){
        int n=nums.size();
        vector<int>dp(n,0);

        dp[0]=nums[0];          //Base case

        for(int i=1;i<n;i++){
            int pick;
            if(i==1){
                pick =nums[i]+0;
            }else{
                pick =nums[i]+dp[i-2];
            }
            int notPick =dp[i-1];
            dp[i]=max(pick,notPick);
        }

        return dp[n-1];
    }
};
int main(){
    vector<int>arr={2,1,1,2};
    //Output : 4
    Solution obj;
    cout<<obj.rob2(arr);
    return 0;
}