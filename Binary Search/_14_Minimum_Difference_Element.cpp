#include<bits/stdc++.h>
using namespace std;
int floor(int arr[],int start,int end,int target){
    int result=-1;
    while(start<=end){
        int mid = start+(end-start)/2;
        if(arr[mid]==target){
            return arr[mid];
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
int MinimumDiffElement(int arr[],int start,int end,int key){
    int prev=floor(arr,start,end,key);
    int next=ceil(arr,start,end,key);


    int x=abs(prev-key);
    int y=abs(next-key);
   
    cout<<x<<" "<<y<<endl;
    if(x>y){
        return next;
    }
    else{
        return prev;
    }
}
int main(){
    int arr[]={1,3,8,11,15};
    int size=sizeof(arr)/sizeof(int);

    cout<<MinimumDiffElement(arr,0,size-1,16);
    return 0;
}