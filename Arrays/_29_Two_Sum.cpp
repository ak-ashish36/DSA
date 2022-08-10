//https://leetcode.com/problems/two-sum/
//https://www.codingninjas.com/codestudio/problems/pair-sum_697295/
//https://youtu.be/dRUpbt8vHpo
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
// T=O(n2)   S=O(1)
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if((nums[i]+nums[j]==target)){
                    ans.push_back(i);
                    ans.push_back(j);
                    break;
                }
            }
            if (ans.size() == 2) break;
        }
        return ans;
    }
// T=O(nlogn)   S=O(1)
    vector<int> twoSum2(vector<int>& nums, int target) {
        vector<int> duplicate =nums;

        sort(duplicate.begin(),duplicate.end());

        int left=0, right=duplicate.size()-1;

        vector<int> ans;
        int num1,num2;
        while(left<right){
            if(duplicate[left]+duplicate[right]==target){
                num1=duplicate[left];
                num2=duplicate[right];
                break;
            }
            else if(duplicate[left]+duplicate[right]>target){
                right--;
            }
            else if(duplicate[left]+duplicate[right]<target){
                left++;
            }
        }
        for(int i=0;i<nums.size();++i){
        	if(nums[i]==num1)
            	ans.push_back(i);
        	else if(nums[i]==num2)
            	ans.push_back(i);
    	}
        return ans;
    }
// T=O(n)   S=O(n)
    vector<int> twoSum3(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); ++i) {
            if (mp.find(target-nums[i]) != mp.end()){
   		    ans.emplace_back(i);
   		    ans.emplace_back(mp[target - nums[i]]);
   		    return ans;
   	    }
   	        mp[nums[i]] = i;
        }
        return ans;
    }
};

int main(){
    vector<int> arr={1,2,3,4};
    int target=7;
    //Output =index{2,3}
    Solution obj;
    vector<int> ans=obj.twoSum2(arr,7);
    for(int i:ans){
        cout<<i<<" ";
    }
   return 0;
}