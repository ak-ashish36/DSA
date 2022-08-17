//https://leetcode.com/problems/number-of-longest-increasing-subsequence/
//https://www.codingninjas.com/codestudio/problems/number-of-longest-increasing-subsequence_3751627/
//https://youtu.be/cKVl1TFdNXg
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);  
        vector<int> count(n,1);    
        int maxi=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j] && dp[j]+1 >dp[i]){
                    dp[i]=dp[j]+1; 
                    count[i]=count[j]; //Inherit
                }
                else if(nums[i]>nums[j] && dp[i]==dp[j]+1){
                    count[i]+=count[j]; //Increase the count
                }
            }  
            maxi=  max(maxi,dp[i]);    
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(dp[i]==maxi){
                ans+=count[i];
            }
        }
        return ans;
    }
};
int main(){
    vector<int>arr={1,3,5,4,7};
    //Output =2 The two LIS are [1, 3, 4, 7] and [1, 3, 5, 7].
    Solution obj;
    cout<<obj.findNumberOfLIS(arr);
    return 0;
}