#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector <int>arr,int k,int max){
    int student_count=1;
    int sum=0;
    for(int i=0;i<arr.size();i++){
        sum+=arr[i];
        if(sum>max){
            student_count++;
            sum=arr[i];
        }
        if(student_count>k){return false;}
    }
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
    int mid = (start + end) >> 1;

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
    int k = 2;
    cout << "Minimum Possible Number is " << books(arr,k);
    return 0;
}