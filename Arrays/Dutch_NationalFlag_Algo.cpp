//https://leetcode.com/problems/sort-colors/
#include<bits/stdc++.h>
using namespace std;

void sortColors(vector<int>& nums) {
        int lo = 0; 
        int hi = nums.size() - 1; 
        int mid = 0; 
        while (mid <= hi) { 
            switch (nums[mid]) {                        //input -{1,0,1,2,2,0,2,1}
            // If the element is 0 
            case 0: 
                swap(nums[lo++], nums[mid++]); 
                break; 
            // If the element is 1 . 
            case 1: 
                mid++; 
                break; 
            // If the element is 2 
            case 2: 
                swap(nums[mid], nums[hi--]); 
                break; 
            }
        }
        for(int i:nums){
            cout<<i;
        }
}
int main(){
     vector<int> nums;
    nums={1,0,1,2,2,0,2,1};
    sortColors(nums);
    return 0;
}