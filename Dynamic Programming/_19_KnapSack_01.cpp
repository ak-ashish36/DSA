//https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
//https://www.codingninjas.com/codestudio/problems/1072980/
//https://youtu.be/kvyShbFVaY8
#include<bits/stdc++.h>
using namespace std;
class Solution{
	public:
	//DP+Memoization Solution
	int knapSack(int W, int wt[], int val[], int n,vector<vector<int>>&dp){
		// Base Case
		if (n == 0 || W == 0){
			return 0;
		}
		if(dp[n][W]!=-1){
			return dp[n][W];
		}

		// If weight of the nth item is more than Knapsack capacity W, then  this item cannot be included in the optimal solution
		if (wt[n - 1] > W)
			return dp[n][W]=knapSack(W, wt, val, n-1,dp);
		// Return the maximum of two cases:(1) nth item included (2) not included
		else
			return dp[n][W]= max(val[n-1]+ knapSack(W-wt[n-1],wt,val,n-1,dp), knapSack(W,wt,val,n-1,dp) );
	}

	int knapSack2(int W, int wt[], int val[], int n,int maxi){

		if (n == 0 || W == 0)
			return maxi;

		if (wt[n - 1] > W)
			return knapSack2(W, wt, val, n - 1,maxi);

		else{
        	return max(knapSack2(W - wt[n - 1],wt, val, n-1,maxi+val[n-1]) , knapSack2(W, wt, val, n-1,maxi) );
    	}
	}

    //Dp+Tabulation Solution
	int knapSack3(int W,int wt[],int val[],int n){
    	vector<vector<int>>dp(n+1,(vector<int>(W+1,-1)));

		for(int i=0;i<n+1;i++){
			for(int j=0;j<W+1;j++){
				if(i==0 || j==0){
					dp[i][j]=0;
				}
				else if(wt[i-1]<=j){
					dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
				}
				else{
					dp[i][j]=dp[i-1][j];
				}
			}
		}

		return dp[n][W];
	}
	
};
// Driver code
int main(){
	int val[] = { 60, 100, 120 };
	int wt[] = { 10, 20, 30 };
	int W = 50;
	int n = sizeof(val) / sizeof(val[0]);
    //Output : 220
    vector<vector<int>>dp(n+1,(vector<int>(W+1,-1)));
	Solution obj;
	cout << obj.knapSack(W, wt, val, n,dp)<<endl;
	cout << obj.knapSack3(W, wt, val, n)<<endl;
	return 0;
}