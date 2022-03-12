#include<bits/stdc++.h>
using namespace std;
int binarySearchInNearlySorted(int arr[],int size,int target){
    int start=0,end=size-1;
    while(start<=end){
        int mid=start + (end-start)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(mid-1>=start && arr[mid-1]==target){
            return mid-1;
        }
        else if(mid+1<=end && arr[mid+1]==target){
            return mid+1;
        }
        else if(arr[mid]>target){
            end=mid-2;
        }
        else{
            start=mid+2;
        }
    }
    return -1;
}
int main(){
    int arr[]={5,10,30,20,40};
    int size=sizeof(arr)/sizeof(int);
    cout<<binarySearchInNearlySorted(arr,size,20)<<endl;
    return 0;
}