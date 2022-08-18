//https://leetcode.com/problems/kth-largest-element-in-an-array/
//https://www.codingninjas.com/codestudio/problems/kth-largest-element_796007/
//https://youtu.be/3DdP6Ef8YZM
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        priority_queue <int, vector<int>, greater<int> > minH;

        for(int i=0;i<nums.size();i++){
            minH.push(nums[i]);
            if(minH.size()>k){
                minH.pop();
            }
        }
        return minH.top();
    }
};
int main(){
    vector<int>arr={3,2,1,5,6,4};
    int k=2;
    //Output = 5 {6,5}
    Solution obj;
    cout<<obj.findKthLargest(arr,k);
    return 0;
}