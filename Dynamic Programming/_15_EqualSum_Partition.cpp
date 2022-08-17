//https://leetcode.com/problems/partition-equal-subset-sum/
//https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1
//https://www.codingninjas.com/codestudio/problems/partition-equal-subset-sum_892980/
//https://youtu.be/7win3dcgo3k
#include<bits/stdc++.h>
using namespace std;
class Solution {
    bool isSubsetSum(vector<int>&arr,int sum){
        int n =arr.size();
    	vector<vector<bool>>dp(n,(vector<bool>(sum+1,false)));

        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
        dp[0][arr[0]]=true;
            
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
public:
    
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%2==1){return false;}
        else{
            return isSubsetSum(nums,sum/2);
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