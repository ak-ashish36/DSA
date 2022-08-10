//https://leetcode.com/problems/search-insert-position/
//https://www.codingninjas.com/codestudio/problems/ceiling-in-a-sorted-array_1825401/
//https://practice.geeksforgeeks.org/problems/ceil-the-floor2802/1
#include<bits/stdc++.h>
using namespace std;

int ceil(vector<int>arr,int target){
    int start=0;
    int end=arr.size()-1;
    int result=-1;
    while(start<=end){
        int mid = start+(end-start)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]>target){
            result=mid;
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return result;
    // return start;
}
int main(){
    vector<int>arr={1,2,3,4,8,10,12};
    cout<<ceil(arr,13);
    //output -1 or 7
    return 0;
}