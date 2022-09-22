//https://leetcode.com/problems/sliding-window-maximum/
//https://practice.geeksforgeeks.org/problems/deee0e8cf9910e7219f663c18d6d640ea0b87f87/1
//https://youtu.be/xFJXtB5vSmM
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        int n=arr.size();
        deque<int> dq;
        int i=0,j=0;
        vector<int>ans;
        for(j=0;j<n;j++){
            while(!dq.empty() && dq.back()<arr[j]){//Always maintain decreasing order from front to back in queue
                dq.pop_back();
            }
            dq.push_back(arr[j]);
            if(j-i+1 == k){
                ans.push_back(dq.front());
                if(dq.front()==arr[i]){
                    dq.pop_front();
                }
                i++;
            }
        }
        return ans;
    }
};
int main(){
    vector<int>arr={1,2,3,1,4,5,2,3,6};
    int k=3;
    Solution obj;
    for(int i :obj.maxSlidingWindow(arr,k)){
        cout<<i<<" ";
    }
    return 0;
}