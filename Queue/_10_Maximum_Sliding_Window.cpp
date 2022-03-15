#include<bits/stdc++.h>
using namespace std;
// Naive Approach T=O(n*K)  S=(k)
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int size=nums.size();
    vector<int>ans;
    int maxi;

    for(int i=0;i<size-(k-1);i++){
        maxi=nums[i];

        for(int j=1;j<k;j++){
            maxi=max(nums[i+j],maxi);
        }
        ans.push_back(maxi);
    }   
    return ans;
}
// Optimised approach T=O(n)  S=O(k)
vector <int>maxSlidingWindow2(vector<int> & nums, int k) {
  deque<int> dq;
  vector<int> ans;
  for (int i = 0; i < nums.size(); i++) {
    if (!dq.empty() && dq.front() == i - k){
      dq.pop_front();
    } 
    
    while (!dq.empty() && nums[dq.back()] < nums[i]){     //Always maintain decreasing order in queue
      dq.pop_back();
    }
    dq.push_back(i);

    if (i >= k - 1){
      ans.push_back(nums[dq.front()]);
    } 
  }
  return ans;
}
int main(){
    vector<int> arr={1,3,-1,-3,5,3,6,7};
    vector<int> ans=maxSlidingWindow2(arr,3);
    for(int i:ans){
        cout<<i<<" ";
    }
    return 0;
}