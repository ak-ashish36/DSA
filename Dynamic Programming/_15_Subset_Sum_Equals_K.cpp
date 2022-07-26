//https://youtu.be/_gPcYovP7wc
//https://www.codingninjas.com/codestudio/problems/subset-sum-equal-to-k_1550954
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
        //Recursive + Memoization Approach
        bool subsetSum(vector<int>&arr,int n,int k,vector<vector<int>>&dp){
            //Base Cases
            if(k==0){           //when k==0 then {null} subset is the ans 
                return true;;
            }
            else if(n==0){      // when n==0 and k!=0 then there is no ans
                return false;
            }

            if(dp[n][k]!=-1){return dp[n][k];}

            if(arr[n-1]<=k){        // if arr last value is less than or equal to the given sum than move next
                return dp[n][k]=subsetSum(arr,n-1,k-arr[n-1],dp) || subsetSum(arr,n-1,k,dp);   //return any function which gives true
            }
            else{
                return dp[n][k]=subsetSum(arr,n-1,k,dp);
            }
        }
        //Tabulation
        bool subsetSum2(vector<int>&arr,int n,int s){

    	    vector<vector<int>>dp(n+1,(vector<int>(s+1,0)));
            
            for(int i=0;i<n;i++){
                dp[i][0]=true;
            }
            
            for(int i=1;i<n+1;i++){
			    for(int j=1;j<s+1;j++){
				    if(arr[i-1]<=j){
					    dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
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
    vector<int>arr={2,3,7,8,10};
    int k=11;
    int n=arr.size();
    Solution obj;
    vector<vector<int>>dp(n+1,(vector<int>(k+1,-1)));
    cout<<"Memoization Sol: "<<obj.subsetSum(arr,n,k,dp)<<endl;
    cout<<"DP Tabulation Sol: "<<obj.subsetSum2(arr,n,k)<<endl;
    return 0;
}