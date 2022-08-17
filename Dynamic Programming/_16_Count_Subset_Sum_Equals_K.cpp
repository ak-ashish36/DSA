//https://www.codingninjas.com/codestudio/problems/number-of-subsets_3952532/
//https://youtu.be/GS_OqZb2CWc
#include<bits/stdc++.h>
using namespace std;
class Solution{
    int solve(int n,int k,vector<int>&arr, vector<vector<int>>&dp){
        //Base Case
        if(k==0){return 1;} //when target==0 then {null} subset is the ans 
        if(n==0){return arr[0]==k;}    // when n==0 return true if last value equals target else false

        if(dp[n][k]!=-1){return dp[n][k];}

        int not_take = solve(n-1,k,arr,dp);
        int take =0;

        if(arr[n]<=k){
            take = solve(n-1,k-arr[n],arr,dp);
        }

        return dp[n][k]=take + not_take;
    }
public:
    //Recursive + Memoization Approach
    int countSubsetSum(vector<int>&arr,int sum){
        int n =arr.size();
        vector<vector<int>>dp(n,(vector<int>(sum+1,-1)));

        return solve(n-1,sum,arr,dp); 
    }
//Tabulation
    int countSubsetSum2(vector<int>&arr,int sum){
        int n =arr.size();
    	vector<vector<int>>dp(n,(vector<int>(sum+1,0)));

        for(int i=0;i<n;i++){
            dp[i][0]=1;
        }
        if(arr[0]<=sum)dp[0][arr[0]]=1;
        
            
        for(int i=1;i<n;i++){
			for(int j=1;j<sum+1;j++){
                int not_take=dp[i-1][j];
                int take=0;
				if(arr[i]<=j){
					take=dp[i-1][j-arr[i]];
				}
                dp[i][j]=take + not_take;
			}
		}
		return dp[n-1][sum];
    }
};
int main(){
    vector<int>arr={1,2,3,4,5};
    //Output : 3
    int k=10;
    Solution obj;
    cout<<"Memoization Sol: "<<obj.countSubsetSum(arr,k)<<endl;
    cout<<"Tabulation Sol: "<<obj.countSubsetSum2(arr,k);
    return 0;
}