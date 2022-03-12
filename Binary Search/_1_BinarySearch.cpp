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
int binarySearchRec(int arr[],int start,int end,int target){
    if(start>end){
        return -1;
    }
    int mid=start + (end-start)/2;
    if(arr[mid]==target){
            return mid;
    }
    else if(arr[mid]>target){
        return binarySearchRec(arr,start,mid-1,target);
    }
    else{
        return binarySearchRec(arr,mid+1,end,target);
    }
    
}

int main(){
    int arr[]={0,1,2,3,4,5,6,7,8,9};
    int size=sizeof(arr)/sizeof(int);
    cout<<binarySearch(arr,0,size-1,4)<<endl;
    cout<<binarySearchRec(arr,0,size-1,4)<<endl;

    return 0;
}