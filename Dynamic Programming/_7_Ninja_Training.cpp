//https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003
//https://youtu.be/AE39gJYuRog
#include<bits/stdc++.h>
using namespace std;
class Solution{
    int sol(int i,int n,vector<vector<int>> &points,int prev,vector<vector<int>>&dp){
        if(i==n){
            int pts=0;
            for(int j=0;j<=2;j++){
                if(j!=prev){
                    pts=max(pts,points[n][j]);
                }
            }
            return pts;
        }
        if(dp[i][prev]!=-1)return dp[i][prev];
        int maxi=0;

        for(int j=0;j<=2;j++){
            if(j!=prev){
                int pts=points[i][j] + sol(i+1,n,points,j,dp);
                maxi=max(maxi,pts);
            }
        }
        return dp[i][prev]=maxi;
    }  
public:
    // Recursion + Memoization   T=O(n*4)*3   S=O(n)+O(n*4) (Stack space + dp vector)
    int ninjaTraining(int n, vector<vector<int>> &points){
        vector<vector<int>>dp(n,vector<int>(4,-1));
        return sol(0,n-1,points,3,dp);
    }

    // Tabulation
    int ninjaTraining2(int n, vector<vector<int>> &points){
        vector<vector<int>>dp(n,vector<int>(3,0));

        dp[0][0]=points[0][0];
	    dp[0][1]=points[0][1];
	    dp[0][2]=points[0][2];

        for(int i=1;i<n;i++){
		    for(int j=0;j<3;j++){
			    dp[i][j]=max( dp[i-1][(j+1)%3] , dp[i-1][(j+2)%3] )+points[i][j];
		    }
	    }
        int ans=0;
	    for(int i=0;i<3;i++){
		    ans=max(ans,dp[n-1][i]);
	    }
	    return ans;
    }
};
int main(){
    vector<vector<int>> points={{1,2,5}, 
                                {3,1,1},
                                {3,3,3}};
    Solution obj;
    cout<<obj.ninjaTraining2(points.size(),points);
    return 0;
}



