#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[],int start,int end,int target){

    while(start<=end){
        int mid=start + (end-start)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]>target){
            start=mid+1;
        }
        else{
            end=mid-1;

        }
    }
    return -1;
}
int binarySearchRec(int arr[],int start,int end,int target){
    if(start>end){
        return -1;
    }
    int mid=start + (end-start)/2;
    if(arr[mid]==target){
            return mid;
    }
    else if(arr[mid]>target){
        return binarySearchRec(arr,mid+1,end,target);
    }
    else{
        return binarySearchRec(arr,start,mid-1,target);
    }
    
}

int main(){
    int arr[]={9,8,7,6,5,4,3,2,1,0};
    int size=sizeof(arr)/sizeof(int);
    cout<<binarySearch(arr,0,size-1,2)<<endl;
    cout<<binarySearchRec(arr,0,size-1,2)<<endl;

    return 0;
}