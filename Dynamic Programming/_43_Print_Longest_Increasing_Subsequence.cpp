//https://youtu.be/IFfYfonAFGc?t=1040
#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    void printLIS(vector<int>& nums) {
        vector<int> dp(nums.size(),1);    // dp vector for storing length of increasing subsequence
        vector<int>hash(nums.size());

        int maxi=1;
        int lastIndex=0;
        for(int i=1;i<nums.size();i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    if(dp[j]+1>dp[i]){
                        dp[i]=dp[j]+1;
                        hash[i]=j;
                    } 
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                lastIndex=i;
            }
        }
        //dp =     {1, 1, 2, 1, 3, 2}
        //last index =4
        //hash =   {0, 1, 0, 3, 2, 0}
        while(hash[lastIndex]!=lastIndex){
            cout<<nums[lastIndex]<<" ";
            lastIndex = hash[lastIndex];
        }
        cout<<nums[lastIndex]<<endl;
    }
};
int main(){
    vector<int>arr={5,4,11,1,16,8};
    //Output = 4 {4,11,16};
    Solution obj; 
    obj.printLIS(arr);
}