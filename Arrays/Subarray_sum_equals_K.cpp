//https://leetcode.com/problems/subarray-sum-equals-k/solution/
#include<bits/stdc++.h>
using namespace std;
// T=O(n2)  S=O(1)
int subarraySum(vector<int>& nums, int k) {
         int count=0;
    for(int i=0;i<nums.size();i++){
        int sum=0;
        for(int j=i;j<nums.size();j++){
            sum += nums[j];
            if(sum==k){
                count++;
            }
        }
    }
    return count;
}
// T=O(n)  S=O(n)
int subarraySum2(vector<int>& nums, int k) {
    unordered_map <int,int> mpp;
    mpp[0]=1;
    int count=0,sum=0;
    for(int i=0;i<nums.size();i++){
        sum+=nums[i];
        if(mpp.find(sum-k)!=mpp.end()){  //Sum found in hash table.
            count=count+mpp[sum-k];
        }
        mpp[sum]++;
    }
    return count;
}
int main(){
    vector<int> arr={1,2,3};
    cout<<subarraySum2(arr,3);
    
   return 0;
}