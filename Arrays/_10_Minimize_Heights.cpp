//https://leetcode.com/problems/smallest-range-ii/
//https://practice.geeksforgeeks.org/problems/minimize-the-heights-i/1
//https://www.codingninjas.com/codestudio/problems/minimize-the-difference_3208652
//https://youtu.be/Av7vSnPSCtw
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans = nums[n-1]-nums[0];
        int lowest = nums[0]+k;
        int greatest = nums[n-1]-k;
        int mi,ma;
        for(int i=0;i<n-1;i++){
            mi = min(lowest,nums[i+1]-k);
            ma = max(greatest,nums[i]+k);
            //In leetcode and gfg minimum can be negative
            // if(mi<0){               
            //     continue;
            // }
            ans=min(ans,ma-mi);
        }
        return ans;
    }
};
int main(){
    vector<int>arr={1, 5, 8, 10};
    int k=2;
    //Output 5 {3,3,6,8}->8-3
    Solution obj;
    cout<<obj.smallestRangeII(arr,k);
    return 0;
}