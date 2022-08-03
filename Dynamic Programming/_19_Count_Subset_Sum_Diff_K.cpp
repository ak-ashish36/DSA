//https://youtu.be/ot_XBHyqpFc
//https://leetcode.com/problems/target-sum/
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
        //DP+Tabulation
        int countSubsetSum(vector<int>&arr,int n,int k){

    	    vector<vector<int>>dp(n+1,(vector<int>(k+1,0)));
            
            for(int i=0;i<n;i++){    
                dp[i][0]=1;
            }
            
            for(int i=1;i<n+1;i++){
			    for(int j=1;j<k+1;j++){

				    if(arr[i-1]<=j){
					    dp[i][j]=dp[i-1][j-arr[i-1]] + dp[i-1][j];
				    }
				    else{
					    dp[i][j]=dp[i-1][j];
				    }
			    }
		    }
		    return dp[n][k];
        }
        int countPartitions(vector<int>&arr,int d){    // Let s1 and s2 are the two subsets
            int sum=0,count=0;                        // we have to find (s1-s2)=d
            for(int i=0;i<arr.size();i++){           // s1+s2=sum and s1-s2=d
                sum+=arr[i];                         // 2s1 =sum+d  => s1 =(sum+d)/2
            }                                        // s1 = (sum+d)/2
            int s1 =abs((sum+d)/2);
            if ((sum+d)%2!=0){return 0;}
            return countSubsetSum(arr,arr.size(),s1);  
        }
};

int main(){
    vector<int>arr={5,2,6,4};
    int d=3;
    //Output : 1
    Solution obj;   
    cout<<obj.countPartitions(arr,d);
    return 0;
}