//https://leetcode.com/problems/maximum-subarray/
//https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1
//https://www.codingninjas.com/codestudio/problems/maximum-subarray-sum_630526
//https://youtu.be/w_KEocd__20
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
//T=O(n2) : S:O(1)
    int maxSubArray(vector<int>& nums,vector<int>&subarray){
        int max_sum = INT_MIN;
        int n = nums.size();
        if (n == 1) {return nums[0];}
        for(int i=0;i<n;i++){           //{-2,1,-3,4,-1,2,1,-5,4}
            int curr_sum=0;
            for(int j=i;j<n;j++){
                curr_sum=curr_sum+nums[j];
                if (curr_sum > max_sum) {
                    subarray.clear();
                    max_sum = curr_sum;
                    subarray.push_back(i);
                    subarray.push_back(j);
                }
            }
        }
        return max_sum;
    }
//T=O(n) : S:O(1) Kadanes Algorithm
    int maxSubArray2(vector < int > & nums, vector < int > & subarray) {
        int max_sum = 0, sum = 0;
        int s = 0;
        for (int i = 0; i < nums.size(); i++) { //{-2,1,-3,4,-1,2,1,-5,4}
            sum += nums[i];
            if (sum > max_sum) {
                subarray.clear();
                max_sum = sum;
                subarray.push_back(s);
                subarray.push_back(i);
            }
            if (sum < 0) {
                sum = 0;
                s = i + 1;
            }
        }
        return max_sum;
    }
};
int main() {
  vector<int> arr{-2,1,-3,4,-1,2,1,-5,4};
  Solution obj;
  //Output = 6 {4,-1,2,1}
  vector <int> subarray;
  int lon = obj.maxSubArray2(arr, subarray);
  cout << "The longest subarray with maximum sum is " << lon << endl;
  cout << "The subarray is " << endl;
  for (int i = subarray[0]; i <= subarray[1]; i++) {
    cout << arr[i] << " ";
  }

}