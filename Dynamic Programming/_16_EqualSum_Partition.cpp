//https://youtu.be/UmMh7xp07kY
//https://leetcode.com/problems/partition-equal-subset-sum/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool subsetSum(vector<int>arr,int n,int s){
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

    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%2==1){return false;}
        else{
            return subsetSum(nums,nums.size(),sum/2);
        }
    }
};
int main(){
    vector<int>arr={1,5,11,5};
    //Output : True
    int n=arr.size();
    Solution obj;
    cout<<"Tabulation Sol: "<<obj.canPartition(arr)<<endl;
    return 0;
}