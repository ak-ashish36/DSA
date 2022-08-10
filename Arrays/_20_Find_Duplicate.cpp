//https://leetcode.com/problems/find-the-duplicate-number/
//https://www.codingninjas.com/codestudio/problems/find-duplicate-in-array_1112602/
//https://youtu.be/32Ll35mhWg0
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
//T :O(n)   S: O(n)
    int findDuplicate(vector<int>arr) {
        int n = arr.size();
        int freq[n + 1] = {0};
        for (int i = 0; i < n; i++) {
            if (freq[arr[i]] == 0) {
                freq[arr[i]] += 1;
            } else {
                return arr[i];
            }
        }
        return 0;
    }
//T:O(n) S:O(1)
    int findDuplicate2(vector<int>&nums){
        int slow = nums[0];
        int fast = nums[0];

        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        fast = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
    
};
int main(){
    vector<int> nums{4,3,6,2,1,1};
    Solution obj;
    cout<<obj.findDuplicate(nums)<<endl;
    cout<<obj.findDuplicate2(nums);
    return 0;
}