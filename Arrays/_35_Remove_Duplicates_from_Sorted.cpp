//https://leetcode.com/problems/remove-duplicates-from-sorted-array/
//https://practice.geeksforgeeks.org/problems/remove-duplicate-elements-from-sorted-array/1
//https://www.codingninjas.com/codestudio/problems/1102307/
//https://youtu.be/Fm_p9lJ4Z_8
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
//Time complexity: O(n*log(n))+O(n)   Space Complexibility:O(n)
    int removeDuplicates(vector<int>& nums) {
        set<int> set;
        for(int i=0;i<nums.size();i++){
            set.insert(nums[i]);
        }
        int k=set.size();
        int j=0;
        for(auto it:set){
            nums[j++]=it;
        }
        for(auto it:nums){
            cout<<it<<" ";
        }
        return k;        
    }
//Time complexity: O(n))   Space Complexibility:O(1)
    int removeDuplicates2(vector<int>& nums) {
        int i=0;
        for(int j=1;j<nums.size();j++){
            if (nums[i] != nums[j]) {
                i++;
                nums[i] = nums[j];
            }
        }
        return i+1;        
    }
};
int main(){
    vector<int>arr={0,0,1,1,1,2,2,3,3,4};
    Solution obj;
    cout<<obj.removeDuplicates(arr);
    return 0;
}