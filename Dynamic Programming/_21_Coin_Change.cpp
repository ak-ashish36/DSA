//https://leetcode.com/problems/coin-change/
//https://practice.geeksforgeeks.org/problems/number-of-coins1824/1
//https://www.codingninjas.com/codestudio/problems/minimum-elements_3843091/
//https://youtu.be/myPeWb3Y68A
#include<bits/stdc++.h>
using namespace std;
class Solution {
    int solve(vector<int>& coins, int amount,int n,vector<vector<int>>&dp){
        //Base Case :if we have only one coin left and the amount is divisible by coin than we return total number of coins for that amount else we return INT MAX
        if(n==0){
            if(amount%coins[0]==0){
                return amount/coins[0];
            }else{return 1e9;}
        }
        if(dp[n][amount]!=-1){return dp[n][amount];}
        int not_take=0+solve(coins,amount,n-1,dp);
        int take=1e9;
        if(coins[n]<=amount){
            take=1+solve(coins,amount-coins[n],n,dp);
        }
        return dp[n][amount]=min(take,not_take);
    }
public:
//Recusrion T=O(2^n) S=O(n)(Stack Space) , Memoization T= O(n*amt)  S : O(n*amt)+O(n)stack space
    int coinChange(vector<int>& coins, int amount){
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans= solve(coins,amount,n-1,dp);
        return ans>=1e9 ? -1 : ans;
    }
//Tabulization T= O(n*amt)  S : O(n*amt)
    int coinChange2(vector<int>& coins, int amount){
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,0));
        //Base Case
        for(int j=0;j<=amount;j++){
            if(j%coins[0]==0){
                dp[0][j] = j/coins[0];
            }else{
                dp[0][j]=1e9;
            }
        }
        for(int i=1;i<n;i++){
			for(int j=0;j<amount+1;j++){

                int not_take=0+dp[i-1][j];
                int take =1e9;
                if(coins[i]<=j){
                    take= 1 +dp[i][j-coins[i]];
                }
                dp[i][j]=min(take,not_take);

			}
		}
        int ans=dp[n-1][amount];
        return ans>=1e9 ? -1 : ans;
    }
};
int main(){
    vector<int>coins={1,2,5};
    int amount=11;
    //Output : 3
    Solution obj;
    cout<<obj.coinChange2(coins,amount);
    return 0;
}