#include<bits/stdc++.h>
using namespace std;

int ceil(int arr[],int start,int end,int target){
    int result=-1;
    while(start<=end){
        int mid = start+(end-start)/2;
        if(arr[mid]==target){
            return arr[mid];
        }
        else if(arr[mid]<target){
            start=mid+1;
        }
        else{
            result=arr[mid];
            end=mid-1;
        }
    }
    return result;

}
int main(){
    int arr[]={1,2,3,4,8,10,12};
    int size=sizeof(arr)/sizeof(int);
    cout<<ceil(arr,0,size-1,5);
     
    return 0;
}