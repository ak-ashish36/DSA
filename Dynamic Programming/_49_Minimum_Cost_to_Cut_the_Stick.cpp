//https://leetcode.com/problems/minimum-cost-to-cut-a-stick/
//https://www.codingninjas.com/codestudio/problems/cost-to-cut-a-chocolate_3208460/
//https://youtu.be/xwomavsC86c
#include <bits/stdc++.h>
using namespace std;
class Solution {
    int solve(int i , int j, vector<int>& cuts,vector<vector<int>>&dp){
        if(i>j){return 0;}

        if(dp[i][j]!=-1){return dp[i][j];}

        int mini=1e9;

        for(int k=i;k<=j;k++){
            int cost = cuts[j+1] -cuts[i-1]+solve(i,k-1,cuts,dp)+solve(k+1,j,cuts,dp);
            mini = min(cost,mini);
        }
        return dp[i][j]=mini;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        int c=cuts.size();
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>>dp(c+1,vector<int>(c+1,-1));
        return solve(1,c,cuts,dp);
    }
//Tabulation
    int minCost2(int n, vector<int>& cuts) {
        int c=cuts.size();
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>>dp(c+2,vector<int>(c+2,0));

        for(int i=c;i>=1;i--){
            for(int j=1;j<=c;j++){
                if(i>j){continue;}
                int mini=1e9;
                for(int k=i;k<=j;k++){
                    int cost = cuts[j+1] -cuts[i-1]+dp[i][k-1]+dp[k+1][j];
                    mini = min(cost,mini);
                }
                dp[i][j]=mini;
            }
        }

        return dp[1][c];
    }
};
int main(){
    vector<int>cuts={1,3,4,5};
    int n=7;
    //Output = 16
    Solution obj;
    cout<<obj.minCost2(n,cuts);
    return 0;
}