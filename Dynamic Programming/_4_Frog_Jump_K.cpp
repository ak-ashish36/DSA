//https://youtu.be/Kmh3rhyEtB8
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int sol(int n,int k,vector<int> &heights,vector<int>&dp){
        if(n<=0){       //Base case when frog is on last step return 0
            return 0;
        }
        if(dp[n]!=-1){return dp[n];}
        int min_step = INT_MAX;

        for(int i=1;i<=k;i++){
            if(n-i>=0){
                int jump = sol(n-i,k,heights,dp) + abs (heights[n]-heights[n-i]);
                min_step=min(min_step,jump);
            }
        }
        return dp[n]=min_step;
    }
    int frogJumpK(int n, int k,vector<int> &heights){
        vector<int>dp(n+1,-1);
        return sol(n-1,k,heights,dp);
    }
};
int main(){
    vector<int>heights={10,30,40,50,20};
    int k=3;
    Solution obj;
    cout<<obj.frogJumpK(5,k,heights);
    return 0;
}