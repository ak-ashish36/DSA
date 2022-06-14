#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &arr,int students,int pages) {
    int cnt = 0;
    int sumAllocated = 0; 
    for(int i = 0;i<arr.size();i++) {
        if(sumAllocated + arr[i] > pages) {
            cnt++; 
            sumAllocated = arr[i];
            if(sumAllocated > pages) return false; 
        }
        else {
            sumAllocated += arr[i];
        }
    }
    if(cnt  >= students) return false; 
    return true;
}
int books(vector <int> & arr, int k) {
  if (k > arr.size()) return -1;
  int start = arr[0];
  int end = 0;

  //to find minimum value and sum of all pages
  for (int i = 0; i < arr.size(); i++) {
    end = end + arr[i];
    start = min(start, arr[i]);
  }

  //binary search
  while (start <= end) {
    int mid = start + (end-start)/2;

    if (isPossible(arr,k,mid )==true) {
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