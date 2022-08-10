//https://leetcode.com/problems/longest-increasing-subsequence/
#include <bits/stdc++.h>
using namespace std;
class Solution {
    int solve(vector<int>& nums,int ind,int prev,int n,vector<vector<int>> &dp){
      // Base Case
        if(ind == n)return 0;
      // DP condition
        if(dp[ind][prev+1] != -1)return dp[ind][prev+1];
        
        int take=0,nottake=0;
        
        // Not take 
        nottake = 0+solve(nums,ind+1,prev,n,dp);
        // Take if condition met and update previous
        if(prev == -1 || nums[ind]>nums[prev])
            take= 1+solve(nums,ind+1,ind,n,dp);
        
        return dp[ind][prev+1] = max(take,nottake);
    }
public:
// Memoisation Solution   
    int lengthOfLIS(vector<int>& nums){
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solve(nums,0,-1,n,dp);
    }
};
class Solution2{
    int lowerbound(vector<int>&arr,int target){
        int s=0;
        int e=arr.size()-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(arr[mid]<target){
                s=mid+1;
            }else{
                e=mid-1;
            }
        }
        return s;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>ans;
        ans.push_back(nums[0]);
     
        for(int i=1;i<nums.size();i++){
            if(nums[i]>ans.back()){
                ans.push_back(nums[i]);
            }
            else{
                int x =lowerbound(ans,nums[i]);
                ans[x]=nums[i];
            }
            
        }
        return ans.size();
    }
};
int main(){
    vector<int>nums={10,9,2,5,3,7,101,18};
    //Output = 4 {2,3,7,18}
    Solution2 obj;
    cout<<obj.lengthOfLIS(nums);
    return 0;
}