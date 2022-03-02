//https://leetcode.com/problems/longest-consecutive-sequence/
#include<bits/stdc++.h>
using namespace std;

//  T=O(nlogn)   S=O(1)
int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0 ){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int max_count=1;
        int count=1;

        for(int i=1;i<nums.size();i++){ 
            if(nums[i]==nums[i-1]+1){
                count++;
            }
            else if(nums[i]!=nums[i-1]){
                count=1;
            }
            if(count>max_count){
                max_count=count;
            }
        }
        return max_count;
}
//  T=O(n)   S=O(n)
int longestConsecutive2(vector<int>& nums) {
    set<int> set;
    int max_count=1;
    for(int i=0;i<nums.size();i++){
        set.insert(nums[i]);
    }
    for(int i=0;i<nums.size();i++){
        if(set.count(nums[i]-1)){
                // Do Nothing
        }
        else{
            int currentNum = nums[i];
            int count = 1;
             while (set.count(currentNum + 1)) {
                currentNum += 1;
                count += 1;
            }
        
            if(count>max_count){
                max_count=count;
            }
        }
    }
    return max_count;

}
int main(){
    vector<int> nums ={1,2,0,1};
    cout<<longestConsecutive2(nums);

   return 0;
}