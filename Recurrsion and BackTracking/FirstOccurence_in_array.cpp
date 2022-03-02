#include<bits/stdc++.h>
using namespace std;

int firstOccurenceInArray(int arr[],int size,int target,int index=0){
    if(index==size){
        return -1;
    }
    if(arr[index]==target){
        return index;
    }
    return firstOccurenceInArray(arr,size,target,index+1);
}
int main(){
    int arr[]={1,2,9,4,5};
    int n= sizeof(arr)/sizeof(int);
    int target=1;
    cout<<firstOccurenceInArray(arr,n,target); 
    return 0;
}