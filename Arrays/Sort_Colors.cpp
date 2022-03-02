//https://leetcode.com/problems/sort-colors/
#include<bits/stdc++.h>
using namespace std;

void sortColors(vector<int>& nums) {
    int x=0,y=0,z=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                x++;
            }
            else if(nums[i]==1){
                y++;
            }
            else{
                z++;
            } 
        }
        nums.clear();
        for(int i=0;i<x;i++){
            nums.push_back(0);
        }
        for(int i=0;i<y;i++){
            nums.push_back(1);
        }
        for(int i=0;i<z;i++){
            nums.push_back(2);
        }
        for(int i:nums){
            cout<<i;
        }
    }
int main(){
    vector<int> nums;
    nums={2,0,2,1,1,0};
    sortColors(nums);
   return 0;
}