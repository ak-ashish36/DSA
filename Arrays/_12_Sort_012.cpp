//https://leetcode.com/problems/sort-colors/
//https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1
//https://www.codingninjas.com/codestudio/problems/sort-0-1-2_631055
//https://youtu.be/oaVa-9wmpns
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
//Time : O(2n)
    void sortColors(vector<int>& nums){
        int x=0,y=0,z=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){x++;}
            else if(nums[i]==1){y++;}
            else{z++;} 
        }
        
        for(int i=0;i<x;i++){
            nums[i]=0;
        }
        for(int i=x;i<y+x;i++){
            nums[i]=1;
        }
        for(int i=x+y;i<z+x+y;i++){
            nums[i]=2;
        }
    }
//Time : O(n)  Dutch National Flag Algorithm
    void sortColors2(vector<int>& nums) {
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
}
};
int main(){
    vector<int> nums{1,0,1,2,2,0,2,1};
    Solution obj;
    obj.sortColors(nums);
    for(int i:nums){
        cout<<i<<" ";
    }
    return 0;
}