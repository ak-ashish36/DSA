// https://leetcode.com/problems/search-in-rotated-sorted-array/
#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[],int start,int end,int target){
    while(start<=end){
        int mid=start + (end-start)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]>target){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return -1;
}
int solution(int arr[],int size,int target){
    if(size==1){
        if(target==arr[0]){
            return 0;
        }else{
            return -1;
        }
    }
    if(size==2){
        if(arr[0]==target){return 0;}
        else if(arr[1]==target){return 1;}
        else{return-1;}
    }
    int start=0,end=size-1;
    int minimum=0;
    while(start<=end){
        int mid=start + (end-start)/2;
        int prev=(mid-1+size)%size;
        int next=(mid+1)%size;
        if(arr[prev]>arr[mid] && arr[mid]<arr[next]){
            minimum=mid;
            break;
        }
        else if(arr[mid]>=arr[0]){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    int x= binarySearch(arr,0,minimum-1,target);
    int y= binarySearch(arr,minimum,size-1,target);
   
    return max(x,y);
}
int main(){
    // int arr[]={11,12,15,18,2,5,6,8};
    int arr[]={5,1,2,3,4};

    int size=sizeof(arr)/sizeof(int);
    cout<<solution(arr,size,1);
    return 0;
}