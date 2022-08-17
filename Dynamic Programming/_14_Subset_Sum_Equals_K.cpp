//// DP on Subsequences/Subset/KnapSack
//https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1
//https://www.codingninjas.com/codestudio/problems/subset-sum-equal-to-k_1550954
//https://youtu.be/fWX9xDmIzRI
#include<bits/stdc++.h>
using namespace std;
class Solution{
    int solve(int n,int k,vector<int>&arr, vector<vector<int>>&dp){
        //Base Case
        if(k==0){return true;} //when target==0 then {null} subset is the ans 
        if(n==0){return arr[0]==k;}    // when n==0 return true if last value equals target else false

        if(dp[n][k]!=-1){return dp[n][k];}

        bool not_take = solve(n-1,k,arr,dp);
        bool take =false;

        if(arr[n]<=k){
            take = solve(n-1,k-arr[n],arr,dp);
        }

        return dp[n][k]=take||not_take;
    }
public:
    //Recursive + Memoization Approach
    bool isSubsetSum(vector<int>&arr,int sum){
        int n =arr.size();
        vector<vector<int>>dp(n,(vector<int>(sum+1,-1)));

        return solve(n-1,sum,arr,dp); 
    }
//Tabulation
    bool isSubsetSum2(vector<int>&arr,int sum){
        int n =arr.size();
    	vector<vector<bool>>dp(n,(vector<bool>(sum+1,false)));

        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
        if(arr[0]<=sum)dp[0][arr[0]]=true;
            
        for(int i=1;i<n;i++){
			for(int j=1;j<sum+1;j++){
                bool not_take=dp[i-1][j];
                bool take=false;
				if(arr[i]<=j){
					take=dp[i-1][j-arr[i]];
				}
                dp[i][j]=take||not_take;
			}
		}
		return dp[n-1][sum];
    }
};
int main(){
    vector<int>arr={2,3,7,8,10};
    int k=11;
    //Output : 1
    Solution obj;
    cout<<"Memoization Sol: "<<obj.isSubsetSum(arr,k)<<endl;
    cout<<"DP Tabulation Sol: "<<obj.isSubsetSum2(arr,k)<<endl;
    return 0;
}