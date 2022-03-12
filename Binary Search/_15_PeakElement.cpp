//https://leetcode.com/problems/find-peak-element/submissions/
#include<bits/stdc++.h>
using namespace std;
int peek(int arr[],int start,int end){
    int size=end+1;
    if(size==1){
        return 0;
    }

    while(start<=end){
        int mid=start + (end-start)/2;
        if(mid >0 && mid<size-1){
            if(arr[mid-1]<arr[mid] && arr[mid]>arr[mid+1]){
                return mid;
            }
            else if(arr[mid-1]>arr[mid]){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
    
        else if(mid==0){
            if(arr[mid]>arr[mid+1]){
                return 0;
            }else{return 1;}
        }
        else if(mid==size-1){
            if(arr[mid]>arr[mid-1]){
                return size-1;
            }else{return size-2;}
        }
    }

    return -1;
}
int main(){
    int arr[]={1,2,1,3,5,6,4};
    int size=sizeof(arr)/sizeof(int);
    cout<<peek(arr,0,size-1);
    return 0;
}