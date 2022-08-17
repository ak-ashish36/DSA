//https://leetcode.com/problems/largest-divisible-subset/
//https://www.codingninjas.com/codestudio/problems/divisible-set_3754960/
//https://youtu.be/gDuZwBW9VvM
#include <bits/stdc++.h>
using namespace std;
class Solution {
//Use the concept of print Longest Increasing Subsequence
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1),hash(n);

        sort(nums.begin(),nums.end());
        int maxi=1,lastIndex=0;
        for(int i=1;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0){
                    if(1+dp[j]>dp[i]){
                        dp[i]=1+dp[j];
                        hash[i]=j;
                    }
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                lastIndex=i;
            }
        }
        vector<int>ans;

        while(hash[lastIndex]!=lastIndex){
            ans.push_back(nums[lastIndex]);
            lastIndex = hash[lastIndex];
        }
        ans.push_back(nums[lastIndex]);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
int main(){
    vector<int>arr={1,4,7,8,16};
    //Output = {1 4 8 16}
    Solution obj;
    for(int i : obj.largestDivisibleSubset(arr)){
        cout<<i<<" ";
    }
    return 0;
}