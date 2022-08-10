//https://leetcode.com/problems/move-zeroes
//https://practice.geeksforgeeks.org/problems/move-all-zeroes-to-end-of-array0751/1
//https://www.codingninjas.com/codestudio/problems/interview-shuriken-41-move-zeroes-to-end_240143
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
//T: O(2n) S: O(n)
    void moveZeroes(vector<int>& nums) {
        vector<int>temp(nums.size());
        int j=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                temp[j++]=nums[i];
            }
        }

        for(int i=j+1;i<nums.size();i++){
            temp[i]=0;
        }
        nums=temp;
    }

//T: O(n) S: O(1)
    void moveZeroes2(vector<int>& nums) {
        int j=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                swap(nums[i],nums[j]);
                j++;
            }
        }
    }
};
int main(){
    vector<int>arr={0,1,0,3,12};
    Solution obj;
    //Output = 1 3 12 0 0
    obj.moveZeroes2(arr);
    for(int i :arr){cout<<i<<" ";}
    return 0;
}