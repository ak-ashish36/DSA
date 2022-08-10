// https://leetcode.com/problems/3sum/
#include<bits/stdc++.h>
using namespace std;
// T=O(n3)   S=O(3K) k=number of triplets
vector<vector<int>> threeSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        for(int i=0;i<nums.size()-2;i++){
            for(int j=i+1;j<nums.size()-1;j++){
                for(int k=j+1;k<nums.size();k++){           
                    if((nums[i]+nums[j]+nums[k]==target)){
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[k]);
                        ans.push_back(temp);
                    }
                }
            }
        }
        return ans;
}
// T=O(n2logn)   S=O(3K) k=number of triplets
vector<vector<int>> threeSum2(vector<int>& nums, int target) {
    vector<vector<int>> ans;
    sort(nums.begin(),nums.end());
    int size=nums.size();
    for(int i=0;i<size;i++){
        int target_2=target-nums[i];
        int left=i+1, right=size-1;
            while(left<right){
                if(nums[left]+nums[right]==target_2){
                    vector<int> triplet(3, 0);
                    triplet[0] = nums[i];
                    triplet[1] = nums[left];
                    triplet[2] = nums[right];
                    ans.push_back(triplet);
                    while (left < right && nums[left] == triplet[1]) ++left;
                    while (left < right && nums[right] == triplet[2]) --right;
                }
                else if(nums[left]+nums[right]>target_2){
                    right--;
                }
                else if(nums[left]+nums[right]<target_2){
                    left++;
                }
            }   
            while (i+1<size && nums[i+1]==nums[i]) ++i;
        }
        return ans;
}
// T=O(n2logn)   S=O(n+3k) n for map and k for no of triplets
vector<vector<int>> threeSum3(vector<int>& nums, int target) {
    vector<vector<int>> ans;
    sort(nums.begin(),nums.end());
    for (int i = 0; i < nums.size(); ++i) {
        unordered_map<int, int> mp;
        for(int j=i+1;j<nums.size();j++){
            int target_2=target-nums[i]-nums[j];
            if (mp.find(target_2) != mp.end()){
                vector<int> triplet(3, 0);
                triplet[0] = nums[i];
                triplet[1] = nums[j];
                triplet[2] = target_2;
   		        ans.push_back(triplet);
                while (j+1<nums.size() && nums[j+1]==nums[j]) ++j;
   	        }
   	        mp[nums[j]]++;
        }
        while (i+1<nums.size() && nums[i+1]==nums[i]) ++i;
    }
    return ans;
}
int main(){
    vector<int> arr;
    arr={-1,0,1,2,-1,-4};
    vector<vector<int>> ans=threeSum3(arr,0);
    for(vector<int> i:ans){
        for(int j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
   return 0;
}