//https://leetcode.com/problems/majority-element-ii/
#include<bits/stdc++.h>
using namespace std;
// T=O(n2)  S=O(1)
vector<int> majorityElement1(vector<int>& nums) {
        int size=nums.size();
        vector<int>ans;
        for(int i=0;i<size;i++){
            int freq=0;
            for(int j=0;j<nums.size();j++){
                if(nums[i]==nums[j]){
                    freq++; 
                }
            }
            if(freq>size/3){
                ans.push_back(nums[i]);
            }
        }
        return ans;
}
// T=O(n)  S=O(n)
vector<int> majorityElement2(vector<int>& nums) {
        int size=nums.size();
        unordered_map<int, int > mpp;
        vector<int>v;
        for(int i = 0; i <size; ++i){                  
            mpp[nums[i]]=mpp[nums[i]]+1;
        }   
        for(auto x : mpp){
            if(x.second > size/3){
                v.push_back(x.first);
            }   
        }
        return v;  
}
// T=O(n)  S=O(1)  uisng Moore Voting Algorithm
vector<int> majorityElement3(vector<int>& nums) {
        int size=nums.size();
        int count1=0,count2=0;
        int candidate1=-1,candidate2=-1;
        for(int i=0;i<size;i++){
            if(count1==0){
                candidate1=nums[i];
            }
            else if(count2==0){
                candidate2=nums[i];
            }
            if(nums[i]==candidate1){
                count1++;
            }
            else if(nums[i]==candidate2){
                count2++;
            }
            else{
                count1--;
                count2--;
            }
        }
        vector<int>ans;
        count1 = count2 = 0;
        for (int i = 0; i < size; i++) {
            if (nums[i] == candidate1)
                count1++;
            else if (nums[i] == candidate2)
                count2++;
        }
        if(count1>size/3)
            ans.push_back(candidate1);
        if(count2>size/3)
            ans.push_back(candidate2);
        return ans;  
}

int main(){
    vector<int> nums;
    nums={3,2,3};
    vector<int> v=majorityElement3(nums);
    for(int i:v){
        cout<<i<<" ";
    }
    
   return 0;
}