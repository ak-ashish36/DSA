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
int infiniteArray(int arr[],int start,int target){

    int end=start+1;
    while(target>arr[end]){
        start=end;
        end=2*end;

    }
    return binarySearch(arr,start,end,target);

}
int main(){
    int arr[]={1,2,3,4,5,6,7,8,9,10,11,12};    //suppose this is infintearray;
    cout<<infiniteArray(arr,0,7);
    return 0;
}