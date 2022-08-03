//https://leetcode.com/problems/coin-change-2/
//https://youtu.be/HgyouUi11zk
#include<bits/stdc++.h>
using namespace std;
class Solution {
    int solve(vector<int>& coins, int amount,int n,vector<vector<int>>&dp){
        //Base Case :if we have only one coin left and the amount is divisible by coin than we return 1 else 0
        if(n==0){
            if(amount%coins[0]==0){
                return 1;
            }else{return 0;}
        }
        if(dp[n][amount]!=-1){return dp[n][amount];}
        int not_take=solve(coins,amount,n-1,dp);
        int take=0;
        if(coins[n]<=amount){
            take=solve(coins,amount-coins[n],n,dp);
        }
        return dp[n][amount]=take+not_take;
    }
public:
//Recusrion T=O(2^n) S=O(n)(Stack Space) , Memoization T= O(n*amt)  S : O(n*amt)+O(n)stack space
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return solve(coins,amount,n-1,dp);
    }
//Tabulization T= O(n*amt)  S : O(n*amt)
    int change2(int amount,vector<int>& coins){
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,0));
        //Base Case
        for(int j=0;j<=amount;j++){
            if(j%coins[0]==0){
                dp[0][j] = 1;
            }else{
                dp[0][j]=0;
            }
        }
        for(int i=1;i<n;i++){
			for(int j=0;j<amount+1;j++){

                int not_take=dp[i-1][j];
                int take =0;
                if(coins[i]<=j){
                    take= dp[i][j-coins[i]];
                }
                dp[i][j]=take+not_take;
			}
		}
        return dp[n-1][amount];
    }
};
int main(){
    vector<int>coins={1,2,5};
    int amount=5;
    //Output : 4
    Solution obj;
    cout<<obj.change2(amount,coins);
    return 0;
}