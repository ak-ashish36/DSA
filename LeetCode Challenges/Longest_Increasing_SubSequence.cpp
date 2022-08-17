//https://leetcode.com/problems/longest-increasing-subsequence/
//https://youtu.be/on2hvxBXJH4
#include <bits/stdc++.h>
using namespace std;
class Solution{
    int lowerbound(vector<int>&arr,int target){
        int s=0;
        int e=arr.size()-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(arr[mid]<target){
                s=mid+1;
            }else{
                e=mid-1;
            }
        }
        return s;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>ans;
        ans.push_back(nums[0]);
     
        for(int i=1;i<nums.size();i++){
            if(nums[i]>ans.back()){
                ans.push_back(nums[i]);
            }
            else{
                int x =lowerbound(ans,nums[i]);
                ans[x]=nums[i];
            }
            
        }
        return ans.size();
    }
};
int main(){
    vector<int>nums={10,9,2,5,3,7,101,18};
    //Output = 4 {2,3,7,18}
    Solution obj;
    cout<<obj.lengthOfLIS(nums);
    return 0;
}