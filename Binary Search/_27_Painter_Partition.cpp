#include<bits/stdc++.h>
using namespace std;
bool isPossible(vector<int>&arr,int painters,int time) {
    int cnt = 0;
    int sumAllocated = 0; 
    for(int i = 0;i<arr.size();i++) {
        if(sumAllocated + arr[i] > time) {
            cnt++; 
            sumAllocated = arr[i];
            if(sumAllocated > time) return false; 
        }
        else {
            sumAllocated += arr[i];
        }
    }
     if(cnt  >= painters) return false; 
    return true; 
}
int paint(vector<int>&arr,int k) {
    if (k > arr.size()) return -1;
    int start=arr[0],end=0;
    int result=-1;
    for(int i=0;i<arr.size();i++){
        start=min(start,arr[i]);
        end=end+arr[i];
    }
    while(start<=end){
        int mid = start + (end-start)/2;
        if (isPossible(arr,k,mid)){
            result=mid;
            end=mid-1;
        }else{
            start=mid+1;
        }
    }
    return start;
}
int main(){
    vector<int>arr={10,20,30,40};
    cout<<paint(arr,2);
    return 0;
}