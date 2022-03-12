#include<bits/stdc++.h>


int firstOccurrence(int arr[],int start,int end,int target){

    int result=-1;
    while(start<=end){
        int mid=start + (end-start)/2;
        if(arr[mid]==target){
            result=mid;
            end=mid-1;
        }
        else if(arr[mid]>target){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return result;
}
int lastOccurrence(int arr[],int start,int end,int target){

    int result=-1;

    while(start<=end){
        int mid=start + (end-start)/2;
        if(arr[mid]==target){
            result=mid;
            start=mid+1;
        }
        else if(arr[mid]>target){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return result;
}
int firstOccurrenceRec(int arr[],int start,int end,int target){
    if(start>end){
        return -1;
    }
    int mid= start + (end - start) / 2;

    if (arr[mid] == target && (mid == 0 || target > arr[mid - 1])){
        return mid;
    }
    else if(arr[mid]<target){
        return firstOccurrenceRec(arr,mid+1,end,target);

    }
    else{
        return firstOccurrenceRec(arr,start,mid-1,target);
    }
    
}
using namespace std;
int main(){
    int arr[]={1,2,3,4,5,6,7,7,7,8,9};
    int size=sizeof(arr)/sizeof(int);

    cout<<firstOccurrence(arr,0,size-1,7)<<endl;
    cout<<lastOccurrence(arr,0,size-1,7)<<endl;

    cout<<firstOccurrenceRec(arr,0,size-1,7)<<endl;


    return 0;
}