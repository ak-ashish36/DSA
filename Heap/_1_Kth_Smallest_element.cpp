//https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1
//https://www.codingninjas.com/codestudio/problems/kth-smallest-element_893056/
//https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
//https://youtu.be/4BfL2Hjvh8g
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int kthSmallest(vector<int>& nums, int k) {
        priority_queue<int>maxH;

        for(int i=0;i<nums.size();i++){
            maxH.push(nums[i]);
            if(maxH.size()>k){
                maxH.pop();
            }
        }
        return maxH.top();
    }
};
int main(){
    vector<int>arr={7,10,4,3,20,15};
    int k=3;
    //Output =7 {3,4,7}
    Solution obj;
    cout<<obj.kthSmallest(arr,k);
    return 0;
}