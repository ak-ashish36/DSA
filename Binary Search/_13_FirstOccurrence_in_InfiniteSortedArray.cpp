#include<bits/stdc++.h>
using namespace std;

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
int infiniteArray(int arr[],int start,int target){

    int end=start+1;
    while(target>arr[end]){
        start=end;
        end=2*end;

    }
    return firstOccurrence(arr,start,end,target);

}
int main(){
    int arr[]={0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1};    //suppose this is infintearray;
    cout<<infiniteArray(arr,0,1);
    return 0;
}