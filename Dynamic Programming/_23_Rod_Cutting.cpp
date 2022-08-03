//https://www.codingninjas.com/codestudio/problems/rod-cutting-problem_800284
//https://youtu.be/SZqAQLjDsag
#include<bits/stdc++.h>
using namespace std;
class Solution{
    int solve(int i,int n,vector<int> &price,vector<vector<int>>&dp){
        if(i==0){
            return n*price[0];
        }
        if(dp[i][n]!=-1){return dp[i][n];}
        int not_take=0+solve(i-1,n,price,dp);
        int take=-1e9;
        int rodlength=i+1;
        if(rodlength<=n){
            take=price[i]+solve(i,n-rodlength,price,dp);
        }
        return dp[i][n]=max(take,not_take);
    }
public:
    int cutRod(vector<int> &price, int n){
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(n-1,n,price,dp);
    }
    int cutRod2(vector<int> &price, int n){
        vector<vector<int>>dp(n,vector<int>(n+1,0));
        //Base Case
        for(int j=0;j<=n;j++){
            dp[0][j]=j*price[0];
        }

        for(int i=1;i<n;i++){
			for(int j=0;j<n+1;j++){

                int not_take=0+dp[i-1][j];
                int take =-1e9;
                int rodlength=i+1;
                if(rodlength<=j){
                    take= price[i]+dp[i][j-rodlength];
                }
                dp[i][j]=max(take,not_take);
			}
		}
        return dp[n-1][n];
    }
//Space Optimised
    int cutRod3(vector<int> &price, int n){
        vector<int>prev(n+1,0);
        //Base Case
        for(int j=0;j<=n;j++){
            prev[j]=j*price[0];
        }

        for(int i=1;i<n;i++){
            vector<int>curr(n+1,0);

			for(int j=0;j<n+1;j++){

                int not_take=0+prev[j];
                int take =-1e9;
                int rodlength=i+1;
                if(rodlength<=j){
                    take= price[i]+curr[j-rodlength];
                }
                curr[j]=max(take,not_take);
			}
            prev=curr;
		}

        return prev[n];
    }

};
int main(){
    vector<int>price={2,5,7,8,10};
    //Output : 12
    Solution obj;
    cout<<obj.cutRod3(price,5);
    return 0;
}
