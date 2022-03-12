#include<bits/stdc++.h>
using namespace std;
int firstOccurrence(int arr[],int size,int target){
    int start=0,end=size-1;
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
int lastOccurrence(int arr[],int size,int target){
    int start=0,end=size-1;
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
int main(){
    int arr[]={1,2,4,5,7,7,7,7,8,9};
    int size=sizeof(arr)/sizeof(int);

    int count = lastOccurrence(arr,size,7) - firstOccurrence(arr,size,7) +1;

    cout<<count<<endl;
     
    return 0;
}