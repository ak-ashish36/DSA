//https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1
//https://www.codingninjas.com/codestudio/problems/allocate-books_1090540
//https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
//https://youtu.be/gYmWHvRHu-s
#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &arr,int students,int pages) {
    int count=1;
    int currPageSum=0;
    for(int i=0;i<arr.size();i++){
        if(currPageSum+arr[i]<=pages){//If curr page sum is less than number of pages than we increase the pagesum
            currPageSum+=arr[i];
        }else{
            count++;
            currPageSum=arr[i];
            if(count>students || currPageSum>pages ){
                return false;
            }
        }
    }
    return true;
}
int books(vector <int> & arr, int k) {
  if (k > arr.size()) return -1;

  int start = 0;
  int end = 0;

  //to find maximum value and sum of all pages
  for (int i = 0; i < arr.size(); i++) {
    end = end + arr[i];
    start = max(start, arr[i]);
  }

  //binary search
  while (start <= end) {
    int mid = start + (end-start)/2;

    if (isPossible(arr,k,mid )) {
      end = mid - 1;
    }
    else {
      start = mid + 1;
    }
  }
  return start;
}
int main(){
    vector<int> arr = {10,20,30,40};
    int k =2;
    cout << "Minimum Possible Number is " << books(arr,k);
    return 0;
}