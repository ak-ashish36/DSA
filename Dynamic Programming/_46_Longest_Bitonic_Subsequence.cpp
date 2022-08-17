//https://practice.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1
//https://www.codingninjas.com/codestudio/problems/longest-bitonic-sequence_1062688/
//https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/
//https://youtu.be/y4vN0WNdrlg
#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int lengthOfLBS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp1(n,1);    
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp1[i]=max(dp1[i],dp1[j]+1);     
                }
            }        
        }
        vector<int> dp2(n,1);    
        for(int i=n-2;i>=0;i--){
            for(int j=n-1;j>i;j--){
                if(nums[i]>nums[j]){
                    dp2[i]=max(dp2[i],dp2[j]+1);     
                }
            }        
        }
        int maxi=1;

        for(int i=0;i<n;i++){
            // In Leetcode question dp1[1] or dp2[1] means the mountain is not increasing  or descreasing
            // if(dp1[i] == 1 || dp2[i] == 1){continue;}   
            maxi=max(maxi,dp1[i]+dp2[i]-1);
        }
        return maxi;
    }
};
int main(){
    vector<int>arr={1,11,2,10,4,5,2,1};
    //Output = 6 =>{1, 2, 10, 4, 2, 1} has length 6.
    Solution obj;
    cout<<obj.lengthOfLBS(arr);
    return 0;
}