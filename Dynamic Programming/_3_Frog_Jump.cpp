//https://youtu.be/EgG3jsGoPvQ
//https://www.codingninjas.com/codestudio/problems/frog-jump_3621012?leftPanelTab=1
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int sol(int n,vector<int> &heights,vector<int>&dp){
        if(n<=0){       //Base case when frog is on last step return 0
            return 0;
        }
        if(dp[n]!=-1){return dp[n];}
        int left = sol(n-1,heights,dp) + abs(heights[n]-heights[n-1]);
        int right = INT_MAX;
        if(n>1){                          // If it is in 2nd step or above then only it can go 2 step down
            right = sol(n-2,heights,dp) + abs(heights[n]-heights[n-2]);
        }

        return dp[n]=min(left,right); 
    }
    int sol2(int n,int i,vector<int>&arr,vector<int>&dp){
        if(i>=n-1){
            return 0;
        }
        if(dp[i]!=-1){return dp[i];};
        int left = sol2(n,i+1,arr,dp) + abs(arr[i]-arr[i+1]);
        int right = INT_MAX;
        if(i<n-2){                                          // If it is in last second stair it cant jump 2 stair
            right = sol2(n,i+2,arr,dp) + abs(arr[i]-arr[i+2]);
        }

        return dp[i]=min(left,right); 
    }

    int frogJump(int n, vector<int> &heights){
        vector<int>dp(n+1,-1);
        return sol(n-1,heights,dp);
        return sol2(n,0,heights,dp);     //Start from 0th step
    }

    int frogJump2(int n,vector<int> &heights){
        vector<int>dp(n+1,0);
        dp[0]=0;

        for(int i=1;i<n;i++){
            int first_step = dp[i-1] + abs(heights[i]-heights[i-1]);
            int second_step=INT_MAX;
            if(i>1){
                second_step= dp[i-2] + abs(heights[i]-heights[i-2]);
            }
            dp[i]= min(first_step,second_step);
        }

        return dp[n-1];

    }
    
};
int main(){
    vector<int>heights={10,20,30,10};
    //Output : 20
    Solution obj;
    cout<<obj.frogJump2(4,heights);

    return 0;
}