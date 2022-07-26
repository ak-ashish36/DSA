//https://www.codingninjas.com/codestudio/problems/count-ways-to-reach-nth-stairs_798650
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int sol(int n,vector<int>&dp){
        if(n==0) return 1;
        if(n<0) return 0;

        if(dp[n]!=-1)return dp[n];


        return dp[n]=sol(n-1,dp)+sol(n-2,dp);
    }
    int countDistinctWays(int nStairs) {
        vector<int>dp(nStairs+1,-1);
        return sol(nStairs,dp);     
    }
};
int main(){
    Solution obj;
    cout<<obj.countDistinctWays(5);
    return 0;
}