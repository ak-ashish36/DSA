#include<bits/stdc++.h>
using namespace std;
// Time complexity: O(nk2). 
vector<int> countDistinct(vector<int>&nums,int k){
    vector<int>ans;

    for(int i=0;i<nums.size()-k+1;i++){
        int dist_count = 0;
        for(int j=0;j<k;j++){
            int l;
            for(l=0;l<j;l++){
                if(nums[i+j]==nums[i+l]){
                    break;
                }
            }
            if(j==l){
                dist_count++;
            }
        }
        ans.push_back(dist_count);
    }
    return ans;
}
//Time complexity O(n)
vector<int> countDistinct2(vector<int>&arr,int k){
    int n=arr.size();
    vector<int>ans;
    // Creates an empty hashmap hm
    unordered_map<int, int> mpp;
 
    // Traverse the first window and store size of hash map
    for (int i = 0; i < k; i++) {
        mpp[arr[i]] += 1;
    }
    ans.push_back(mpp.size());
  
    // Traverse through the remaining array
    for (int i = k; i < n; i++) {
        // Remove first element of previous window
        // If there was only one occurrence, then reduce distinct count.
        if (mpp[arr[i - k]] == 1) {
            mpp.erase(arr[i-k]);
        }
        else{
            // reduce count of the removed element
            mpp[arr[i - k]] -= 1;
        }
        // Add new element of current window
        mpp[arr[i]] += 1;
        ans.push_back(mpp.size());
    }
    return ans;
}
int main(){
    vector<int>arr={1,2,1,3,4,2,3};
    vector<int>ans=countDistinct2(arr,4);
    for(int i:ans){
        cout<<i<<" ";
    }

    return 0;
}