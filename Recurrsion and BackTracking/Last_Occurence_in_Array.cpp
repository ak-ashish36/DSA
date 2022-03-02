#include<bits/stdc++.h>
using namespace std;

int lastOccurenceInArray(int arr[],int size,int target,int index){
    if(index==size){
        return -1;
    } 
    if(arr[index]==target){
        return index;
    }
    return lastOccurenceInArray(arr,size,target,index-1);

}
int lastOccurenceInArray2(int arr[],int size,int target,int index){
    if(index==size){
        return -1;
    }

    if(lastOccurenceInArray2(arr,size,target,index+1)==-1 ){
        if(arr[index]=target){return index;}
        else{return -1;}
    }
    else{
        return lastOccurenceInArray2(arr,size,target,index+1);
    }

}
int main(){
    int arr[]={1,2,3,4,5,2,7,6,7};
    int n= sizeof(arr)/sizeof(int);
    int target=7;
    cout<<lastOccurenceInArray(arr,n,target,n-1)<<endl; 

    cout<<lastOccurenceInArray2(arr,n,target,0); 
    return 0;
}