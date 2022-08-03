//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv
//https://youtu.be/IV1dHbk5CDc
#include<bits/stdc++.h>
using namespace std;
class Solution {
    int solve(int i,int buy,vector<int>& prices,int trans,vector<vector<vector<int>>>&dp){
        //Base Case , If available trans ==0 or If no of days exhausted
        if(trans==0 || i==prices.size()){
            return 0;
        }
        if(dp[i][buy][trans]!=-1){return dp[i][buy][trans];}
        int profit=0;


        if(buy){
            int yes = -prices[i]+solve(i+1,0,prices,trans,dp);
            int no = solve(i+1,1,prices,trans,dp);
            profit= max( yes, no);
        }else{//sell
            int yes=prices[i]+solve(i+1,1,prices,trans-1,dp); // when we sell one transaction is completed
            int no = solve(i+1,0,prices,trans,dp);
            profit = max(yes,no);
        }
        return dp[i][buy][trans]=profit;
    }
public:
//Memoization T:O(n*2*3) S : O(n*2*3)+O(n)
    int maxProfit(int k , vector<int>& prices) {
        int n=prices.size();
        // Creating a 3d - dp of size [n][2][k+1]
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return solve(0,1,prices,k,dp);
    }
//Tabulation
    int maxProfit2(int k , vector<int>& prices) {
        int n=prices.size();
        // Creating a 3d - dp of size [n+1][2][k+1]
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        //Base Cases
        for(int i=0;i<=n;i++){
            for(int j=0;j<2;j++){
                dp[i][j][0]=0;
            }
        }
        for(int j=0;j<2;j++){
            for(int l=0;l<=k;l++){
                dp[n][j][l]=0;
            }
        }

        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                for(int l=1;l<=k;l++){   //for k=0 dp will be 0 i.e base condition
                    int profit=0;
                    if(j==1){
                        int yes = -prices[i]+dp[i+1][0][l];
                        int no = dp[i+1][1][l];
                        profit= max( yes, no);
                    }else{
                        int yes = prices[i]+dp[i+1][1][l-1];
                        int no = dp[i+1][0][l];
                        profit= max( yes, no);
                    }
                    dp[i][j][l]=profit;
                }
            }
        }
        return dp[0][1][k];
    } 

//Space Optimization T:O(n*2*3) S: O(2*3)=O(1)
    int maxProfit3(int k , vector<int>& prices) {
        int n=prices.size();
        // Creating a 3d - dp of size [n][2][k+1]
        vector<vector<int>>ahead(2,vector<int>(k+1,0)),curr(2,vector<int>(k+1,0));
        
        //Base Cases
        for(int j=0;j<2;j++){
            ahead[j][0]=0;
        }

        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                for(int l=1;l<=k;l++){   //for k=0 dp will be 0 i.e base condition
                    int profit=0;
                    if(j==1){
                        int yes = -prices[i]+ahead[0][l];
                        int no = ahead[1][l];
                        profit= max( yes, no);
                    }else{
                        int yes = prices[i]+ahead[1][l-1];
                        int no = ahead[0][l];
                        profit= max( yes, no);
                    }
                    curr[j][l]=profit;
                }
            }
            ahead=curr;
        }
        return ahead[1][k];
    }    
};
int main(){
    vector<int>prices={3,2,6,5,0,3};
    int k=2;
    //Output=7
    Solution obj;
    cout<<obj.maxProfit3(k,prices);
    return 0;
}