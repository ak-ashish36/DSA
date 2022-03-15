#include<bits/stdc++.h>
using namespace std;
vector<int> negSlidingWindow(vector<int>nums,int k){
    deque<int> dq;
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++) {

        if (!dq.empty() && dq.front() == i - k){
           dq.pop_front(); 
        } 

        if(nums[i]<0){
            dq.push_back(i);
        }

        // while (!dq.empty() && nums[dq.back()] > 0){
        // dq.pop_back();
        // }

        if (i >= k - 1){
            if(dq.empty()){
                ans.push_back(0);
            }else{
                ans.push_back(nums[dq.front()]);
            }
        } 
    }
  return ans;
}
int main(){
    vector<int> arr={-8,2,3,-6,10};
    vector<int> ans=negSlidingWindow(arr,2);
    for(int i:ans){
        cout<<i<<" ";
    }
    return 0; 
    return 0;
}