#include<bits/stdc++.h>
using namespace std;

int solution(int arr[],int size){
    if(size<=2){
        if(size==1 || arr[1]>arr[0]){
            return 0;
        }else{
            return 1;
        }
    }
    int start=0,end=size-1;
    int minimum=0;

    while(start<=end){

        int mid=start + (end-start)/2;

        int prev=(mid-1+size)%size;
        int next=(mid+1)%size;
        if(arr[prev]>arr[mid] && arr[mid]<arr[next]){
            minimum=mid;
            break;
        }
        else if(arr[mid]>=arr[0]){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    if(minimum==0){return 0;}
    return (size-minimum);
}
int main(){
    // int arr[]={11,12,15,18,2,5,6,8};
    int arr[]={5,1,2,3,4}; 

    int size=sizeof(arr)/sizeof(int);
    cout<<solution(arr,size);
    return 0;
}