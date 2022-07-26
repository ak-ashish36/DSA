//https://youtu.be/F7wqWbqYn9g
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
        //Memoization Solution
        int countSubsetSum(vector<int>&arr,int n,int k,vector<vector<int>>&dp){
            //Base Cases
            if(k==0){
                return 1;
            }
            else if(n==0){
                return 0;
            }
            if(dp[n][k]!=-1){return dp[n][k];}

            if(arr[n-1]<=k){
                int res= countSubsetSum(arr,n-1,k-arr[n-1],dp) + countSubsetSum(arr,n-1,k,dp);
                return dp[n][k]=res;
            }
            else{
                return dp[n][k]= countSubsetSum(arr,n-1,k,dp);
            }

        }
        //Tabulation
        int countSubsetSum2(vector<int>&arr,int n,int s){

    	    vector<vector<int>>dp(n+1,(vector<int>(s+1,0)));
            
            for(int i=0;i<n;i++){
                dp[i][0]=1;
            }
            
            for(int i=1;i<n+1;i++){
			    for(int j=1;j<s+1;j++){

				    if(arr[i-1]<=j){
					    dp[i][j]=dp[i-1][j-arr[i-1]] + dp[i-1][j];
				    }
				    else{
					    dp[i][j]=dp[i-1][j];
				    }
			    }
		    }
		    return dp[n][s];
        }
};
int main(){
    vector<int>arr={1,2,3,4,5};
    int n=arr.size();
    int k=10;
    Solution obj;
    vector<vector<int>>dp(n+1,(vector<int>(k+1,-1)));
    cout<<"Memoization Sol: "<<obj.countSubsetSum(arr,n,k,dp)<<endl;
    cout<<"Tabulation Sol: "<<obj.countSubsetSum2(arr,n,k);
    return 0;
}