//https://leetcode.com/problems/climbing-stairs/submissions/
//https://practice.geeksforgeeks.org/problems/count-ways-to-reach-the-nth-stair-1587115620/1
//https://www.codingninjas.com/codestudio/problems/count-ways-to-reach-nth-stairs_798650/
//https://youtu.be/mLfjzJsN8us
#include<bits/stdc++.h>
using namespace std;
class Solution{
    int sol(int n,vector<int>&dp){
        if(n==0) return 1;
        if(n<0) return 0;

        if(dp[n]!=-1)return dp[n];

        return dp[n]=sol(n-1,dp)+sol(n-2,dp);
    }
public:
    int climbStairs(int n){
        vector<int>dp(n+1,-1);
        return sol(n,dp);     
    }
};
int main(){
    int n=5;
    //Output : 8
    Solution obj;
    cout<<obj.climbStairs(n);
    return 0;
}