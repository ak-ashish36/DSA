//https://leetcode.com/problems/majority-element/
//https://practice.geeksforgeeks.org/problems/majority-element-1587115620/1
//https://www.codingninjas.com/codestudio/problems/majority-element_842495
//https://youtu.be/AoX3BPWNnoE
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
// T=O(n2)  S=O(1)
    int majorityElement(vector<int>& nums) {
       int size=nums.size();
        int ans=-1;
        for(int i=0;i<size;i++){
            int freq=0;
            for(int j=0;j<nums.size();j++){
                if(nums[i]==nums[j]){
                    freq++; 
                    if(freq>=size/2){
                        ans= nums[i];
                        break;
                    }
                }
            }
        }
        return ans;
    }
// T=O(n)  S=O(n)
    int majorityElement2(vector<int>& nums) {
        int size=nums.size();
        unordered_map<int, int > mpp;
        int ans=-1;
        for(int i = 0; i <size; ++i){                  
            mpp[nums[i]]=mpp[nums[i]]+1;
        }   
        for(auto x : mpp){
            if(x.second > size/2){
                ans = x.first;
                break;
            }   
        }
        return ans;  
    }
// T=O(n)  S=O(1)  uisng Moore Voting Algorithm
    int majorityElement3(vector<int>& nums) {
        int size=nums.size();
        int count =0;
        int candidate=0;
        for(int i=0;i<size;i++){
            if(count==0){
                candidate=nums[i];
            }
            if(nums[i]==candidate){
                count++;
            }
            else{
                count--;
            }
        }
        return candidate;  
    }   
};

int main(){
    vector<int> nums;
    nums={2,2,1,1,1,2,2};
    // Output= 2
    Solution obj;
    cout<<obj.majorityElement3(nums);
   return 0;
}