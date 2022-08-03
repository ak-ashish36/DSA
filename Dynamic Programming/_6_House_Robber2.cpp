//https://leetcode.com/problems/house-robber-ii/
//https://youtu.be/3WaxQMELSkw
#include<bits/stdc++.h>
using namespace std;
class Solution{
    // Recursion T=(2^n) + Memoization   T=O(n)   S=O(n)+O(n) (Stack space + dp arr)
    int sol(int n,vector<int>& nums, vector<int>&dp){           
        if(n==0){return nums[n];}
        if(n<0){return 0;}

        if(dp[n]!=-1){return dp[n];}
        
        int pick = nums[n]+sol(n-2,nums,dp);
        int notpick =sol(n-1,nums,dp);
        
        return dp[n]=max(pick,notpick);
    }
    public:
    int rob(vector<int>& nums) {
        int n= nums.size();
        if(n==1){return nums[0];}
        vector<int>dp(n,-1);
        vector<int>temp1,temp2;
    //  Answer will contain either last element or first element
        for(int i =0;i<n;i++){                      
            if(i!=0){temp1.push_back(nums[i]);}     // temp1 doesn't contains 1st elem
            if(i!=n-1){temp2.push_back(nums[i]);}   // temp2 doesn't contains last elem
        }
        int ans1=sol(n-2, temp1, dp);
        dp.assign(n,-1);
        int ans2=sol(n-2, temp2, dp);
        return max(ans1,ans2); 
    }
};
int main(){
    vector<int>arr={2,3,2};
    //Output : 3
    Solution obj;
    cout<<obj.rob(arr);
    return 0;
    return 0;
}