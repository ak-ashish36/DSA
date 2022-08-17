//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown
//https://www.codingninjas.com/codestudio/problems/highway-billboards_3125969//
//https://youtu.be/IGIe46xw3YY
#include<bits/stdc++.h>
using namespace std;
class Solution {
    //If buy=1 ,we can buy else we have to sell the previous stock to buy again
    int solve(int i,int buy,vector<int>& prices,vector<vector<int>>&dp){
        //Base Case , If no of days exhausted
        if(i>=prices.size()){
            return 0;
        }
        if(dp[i][buy]!=-1){return dp[i][buy];}
        int profit=0;

        //{7,1,5,3,6,4}; if we buy 7 and sell at 5 that total profit =-2, i.e 5-7 = -7+5 = -2.
        if(buy){
            int yes = -prices[i]+solve(i+1,0,prices,dp);
            int no = solve(i+1,1,prices,dp);
            profit= max( yes, no);
        }else{//sell
            int yes=prices[i]+solve(i+2,1,prices,dp);//After sell one trans completed than we can buy only after i+2 day
            int no = solve(i+1,0,prices,dp);
            profit = max(yes,no);
        }
        return dp[i][buy]=profit;
    }
public:
//Memoization
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(0,1,prices,dp);
    }

//Tabulation
    int maxProfit2(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+2,vector<int>(2,0));
        //Base Case
        dp[n][0]=dp[n][1]=0;
        dp[n+1][0]=dp[n+1][1]=0;

        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                int profit=0;
                if(buy){
                    profit= max(-prices[i]+dp[i+1][0] , dp[i+1][1]);
                }else{//sell
                    profit = max(prices[i]+dp[i+2][1] , dp[i+1][0]);
                }
                dp[i][buy]=profit;
            }
        }
        
        return dp[0][1];
    }
};
int main(){
    vector<int>prices={1,2,3,0,2};
    //Output : 3
    Solution obj;
    cout<<obj.maxProfit2(prices); 
    return 0;
}