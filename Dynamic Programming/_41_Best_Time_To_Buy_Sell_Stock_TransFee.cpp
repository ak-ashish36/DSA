//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
//https://www.codingninjas.com/codestudio/problems/rahul-and-his-chocolates_3118974
//https://youtu.be/k4eK-vEmnKg
#include<bits/stdc++.h>
using namespace std;
class Solution {
    //If buy=1 ,we can buy else we have to sell the previous stock to buy again
    int solve(int i,int buy,vector<int>& prices,int fee,vector<vector<int>>&dp){
        //Base Case , If no of days exhausted
        if(i==prices.size()){
            return 0;
        }
        if(dp[i][buy]!=-1){return dp[i][buy];}
        int profit=0;

        //{7,1,5,3,6,4}; if we buy 7 and sell at 5 that total profit =-2, i.e 5-7 = -7+5 = -2.
        if(buy){
            int yes = -prices[i]+solve(i+1,0,prices,fee,dp);
            int no = solve(i+1,1,prices,fee,dp);
            profit= max( yes, no);
        }else{//sell
            int yes=prices[i]-fee+solve(i+1,1,prices,fee,dp);  //Deduct the price of fee after selling
            int no = solve(i+1,0,prices,fee,dp);
            profit = max(yes,no);
        }
        return dp[i][buy]=profit;
    }
public:
//Memoization
    int maxProfit(vector<int>& prices,int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(0,1,prices,fee,dp);
    }

//Tabulation
    int maxProfit2(vector<int>& prices,int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        dp[n][0]=dp[n][1]=0;

        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                int profit=0;
                if(buy){
                    profit= max(-prices[i]-fee+dp[i+1][0] , dp[i+1][1]);
                }else{//sell
                    profit = max(prices[i]+dp[i+1][1] , dp[i+1][0]);
                }
                dp[i][buy]=profit;
            }
        }
        
        return dp[0][1];
    }
    //Space optimization
    int maxProfit3(vector<int>& prices,int fee) {
        int n=prices.size();
        vector<int>ahead(2,0),curr(2,0);

        ahead[0]=ahead[1]=0;

        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                int profit=0;
                if(buy){
                    profit= max(-prices[i]-fee+ahead[0] , ahead[1]);
                }else{//sell
                    profit = max(prices[i]+ahead[1] , ahead[0]);
                }
                curr[buy]=profit;
            }
            ahead=curr;
        }

        return ahead[1];
    }

};
int main(){
    vector<int>prices={1,3,2,8,4,9};
    int fee=2; 
    //Output : 8
    Solution obj;
    cout<<obj.maxProfit2(prices,fee);
    return 0;
}