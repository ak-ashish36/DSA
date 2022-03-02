//https://leetcode.com/problems/maximum-subarray/
#include<bits/stdc++.h>
using namespace std;
//T=O(n3)
int maxSubArray(vector < int > & nums, vector < int > & subarray) {
  int max_sum = 0;
  int n = nums.size();
  if (n == 1) {
    return nums[0];
  }
  int i, j;
  for (i = 0; i <= n - 1; i++) {          //{-2,1,-3,4,-1,2,1,-5,4}
    for (j = i; j <= n - 1; j++) {
      int sum = 0;
      for (int k = i; k <= j; k++){
        sum = sum + nums[k];
      }
      if (sum > max_sum) {
        subarray.clear();
        max_sum = sum;
        subarray.push_back(i);
        subarray.push_back(j);

      }
    }
  }
  return max_sum;
}
//T=O(n2)
int maxSubArray2(vector < int > & nums, vector < int > & subarray) {
    int max_sum = INT_MIN;
    int n = nums.size();
    if (n == 1) {
    return nums[0];
    }
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

int main() {
  vector<int> arr{-2,1,-3,4,-1,2,1,-5,4};
  vector < int > subarray;
  int lon = maxSubArray2(arr, subarray);
  cout << "The longest subarray with maximum sum is " << lon << endl;
  cout << "The subarray is " << endl;
  for (int i = subarray[0]; i <= subarray[1]; i++) {
    cout << arr[i] << " ";
  }

}