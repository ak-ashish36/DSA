#include<bits/stdc++.h>
using namespace std;

int floor(int arr[],int start,int end,int target){
    int result=-1;
    while(start<=end){
        int mid = start+(end-start)/2;
        if(arr[mid]==target){
            return arr[mid-1];
        }
        else if(arr[mid]<target){
            result=arr[mid];
            start=mid+1;

        }
        else{
            end=mid-1;
        }
    }
    return result;

}
int main(){
    int arr[]={1,2,3,4,8,10,12};
    int size=sizeof(arr)/sizeof(int);
    cout<<floor(arr,0,size-1,1);
     
    return 0;
}