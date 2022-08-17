//https://leetcode.com/problems/last-stone-weight-ii/submissions/
//https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1
//https://www.codingninjas.com/codestudio/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494/
//https://youtu.be/GS_OqZb2CWc
#include<bits/stdc++.h>
using namespace std;
class Solution{
    vector<int> isSubsetSum(vector<int>&arr,int sum){
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
		vector<int>v;                       // Store the possible values of s1 from 0 to sum
        for(int i=0;i<=sum/2;i++){
            if(dp[n-1][i]){                 //Checking last row of DP
                v.push_back(i);
            }
        }
        for(int i:v){
            cout<<i<<" ";
        }
		return v;
    }
public:
    int minSubsetDiff(vector<int>&arr){
        if(arr.size()==1){return arr[0];}   // Let s1 and s2 are the two subsets
        int total_sum=0;                    // we have to find min(abs(s1-s2))
        for(int i=0;i<arr.size();i++){      // s1+s2=sum of all values
            total_sum+=arr[i];              // s2 =sum-s1
        }                                   // ans = min(sum-s1-s1)                                      
        vector<int>s1=isSubsetSum(arr,total_sum);
        int mini=INT_MAX;
        for(int i=0;i<s1.size();i++){
            int s2=total_sum-s1[i];
            mini=min(mini,abs(s1[i]-s2));
        }
        return mini;
    }
};
int main(){
    vector<int>arr={-36,36};
    //Output : 1 [{1,5,6}-{11}]
    Solution obj; 
    cout<<obj.minSubsetDiff(arr);
    return 0;
}