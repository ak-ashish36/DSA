//https://leetcode.com/problems/maximum-subarray/
#include<bits/stdc++.h>

 using namespace std;
int maxSubArray(vector < int > & nums, vector < int > & subarray) {
  int max_sum = nums[0], sum = 0;
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

int main() {
  vector<int> arr{-2,-3,4,-1,-2,1,5,-3};
  vector < int > subarray;
  int lon = maxSubArray(arr, subarray);
  cout << "The longest subarray with maximum sum is " << lon << endl;
  cout << "The subarray is " << endl;
  for (int i = subarray[0]; i <= subarray[1]; i++) {
    cout << arr[i] << " ";
  }

}