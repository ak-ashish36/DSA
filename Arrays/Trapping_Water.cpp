//https://leetcode.com/problems/trapping-rain-water/
#include<bits/stdc++.h>
using namespace std;
int maxelement(vector<int> arr,int s,int e){
    int max=0;
    for(int i=s;i<e;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    return max;
}
//T=O(n2)  S=O(1)
int trap(vector<int>& height) {
    int waterTrapped = 0;
    int n=height.size();
    for (int i = 0; i <n; i++) {
        int leftMax=maxelement(height,0,i+1);
        int rightMax=maxelement(height,i,n);
        waterTrapped += min(leftMax, rightMax) - height[i];
    }
  return waterTrapped;       
}
//T=O(3n)  S=O(2n)
int trap2(vector<int>& arr) {
    int n = arr.size();
    int prefix[n], suffix[n];
    prefix[0] = arr[0];
    for (int i = 1; i < n; i++) {
        prefix[i] = max(prefix[i - 1], arr[i]);
    }
    suffix[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        suffix[i] = max(suffix[i + 1], arr[i]);
    }
    int waterTrapped = 0;
    for (int i = 0; i < n; i++) {
        waterTrapped += min(prefix[i], suffix[i]) - arr[i];
    }
    return waterTrapped;
}
//T=O(n)  S=O(1)
int trap3(vector < int > & height) {
  int n = height.size();
  int left = 0, right = n - 1;
  int res = 0;
  int maxLeft = 0, maxRight = 0;
  while (left <= right) {
    if (height[left] <= height[right]) {
      if (height[left] >= maxLeft) {
        maxLeft = height[left];
      } else {
        res += maxLeft - height[left];
      }
      left++;
    } else {
      if (height[right] >= maxRight) {
        maxRight = height[right];
      } else {
        res += maxRight - height[right];
      }
      right--;
    }
  }
  return res;
}
int main(){
    vector < int > arr;
  arr = {0,1,0,2,1,0,1,3,2,1,2,1};
  cout << "The water that can be trapped is " << trap2(arr) << endl;
// trap(arr);
    return 0;
}