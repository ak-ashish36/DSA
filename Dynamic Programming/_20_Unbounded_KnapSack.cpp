//Dp on Unbounded KnapSack
//https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1
//https://www.codingninjas.com/codestudio/problems/unbounded-knapsack_1215029/
//https://youtu.be/OgvOZ6OrJoY
#include<bits/stdc++.h>
using namespace std;
class Solution{
    int solve(int n,int W,vector<int> &value,vector<int> &weight,vector<vector<int>>&dp){
        // Base Case if we are at idx 0 we try to get the max W from last available W
        if (n==0) {
            return (W/weight[0]) * value[0];
        }
        // There are two cases either take element or not take.

        if(dp[n][W]!=-1){return dp[n][W];}
        // If not take then
        int notTake= 0 + solve(n-1,W, value, weight,dp);

        // if take then weight = W-wt[n] and index will remain same.
        int take = -1e8;
        if (weight[n] <= W) {
            take = value[n]+ solve(n,W-weight[n],value,weight,dp);
        }
        return dp[n][W]=max(take, notTake);
    }
public:
//Recusrion T=O(2^n) S=O(n)(Stack Space) , Memoization T= O(n*W)  S : O(n*W)+O(n)stack space
    int unboundedKnapsack(int W,vector<int> &value,vector<int> &weight){
        int n=value.size();
        vector<vector<int>>dp(n,vector<int>(W+1,-1));
        return solve(n-1,W,value,weight,dp);
    }
//Tabulization T= O(n*W)  S : O(n*W)
    int unboundedKnapsack2(int W,vector<int> &value,vector<int> &weight){
        int n=value.size();
        vector<vector<int>>dp(n,vector<int>(W+1,0));

        //Base Case
        for(int j=0;j<W+1;j++){
            dp[0][j]=(j/weight[0]) * value[0];
        }
        for(int i=1;i<n;i++){
			for(int j=0;j<W+1;j++){

                int not_take=0+dp[i-1][j];
                int take =-1e8;
                if(weight[i]<=j){
                    take=value[i]+dp[i][j-weight[i]];
                }
                dp[i][j]=max(take,not_take);
                
			}
		}
        return dp[n-1][W];
    }
};
int main(){
    vector<int>value={1,1};
    vector<int>weight={2,1};
    int W=3;
    //Output : 3
    Solution obj; 
    cout<<obj.unboundedKnapsack2(W,value,weight);
    return 0;
}