//https://practice.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1
// https://www.codingninjas.com/codestudio/problems/find-floor-value_920447
#include<bits/stdc++.h>
using namespace std;

int floor(vector<int>arr,int target){
    int start=0,end=arr.size()-1;
    int result=-1;
    while(start<=end){
        int mid = start+(end-start)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]>target){
            end=mid-1;
        }
        else{
            result=mid;
            start=mid+1;
        }
    }
    return result;
}
int main(){
    vector<int>arr={1,2,3,4,8,10,12};
    cout<<floor(arr,13);
    //Output = 6
    return 0;
}