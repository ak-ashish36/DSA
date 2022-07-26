//https://youtu.be/-GtpxG6l_Mc
//https://www.interviewbit.com/problems/minimum-difference-subsets/
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
        //DP+Tabulation
        vector<int> subsetSum(vector<int>&arr,int n,int s){

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
            vector<int>v;                       // Store the values of all s1 where s1 is possible for the given arr
            for(int i=0;i<=s/2;i++){
                if(dp[n][i]){   
                    v.push_back(i);
                }
            }

		    return v;
        }
        int minSubsetDiff(vector<int>&arr){
            if(arr.size()==1){return arr[0];}    // Let s1 and s2 are the two subsets
            int sum=0;                          // we have to find min(abs(s2-s1)) // s1 is left of middle and s2 is right so ignore abs
            for(int i=0;i<arr.size();i++){      // s1+s2=sum of all values
                sum+=arr[i];                    // s2 =sum-s1
            }                                   // ans = min(sum-s1-s1)
                                                
            vector<int>s1=subsetSum(arr,arr.size(),sum);
            int mini=INT_MAX;
            for(int i=0;i<s1.size();i++){
                mini=min(mini,sum-2*s1[i]);
            }
            return mini;
        }
};
int main(){
    vector<int>arr={1,6,11,5};
    Solution obj;
    cout<<obj.minSubsetDiff(arr);
    return 0;
}