//https://leetcode.com/problems/max-consecutive-ones-iii/
//https://practice.geeksforgeeks.org/problems/maximize-number-of-1s0905/1
//https://www.codingninjas.com/codestudio/problems/maximum-consecutive-ones_892994
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
    }
};
int main(){
    vector<int>arr ={1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;
    // Output: 6    [1,1,1,0,0,1,1,1,1,1,1]
    Solution obj;
    cout<<obj.longestOnes(arr,k);
    return 0;
}