//https://youtu.be/wWhAhp6PIuQ
#include<bits/stdc++.h>
using namespace std;
void insertionSort(int arr[],int n){

    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[]={23,4,6,14,7,11,34,9};
    int n= sizeof(arr)/sizeof(int);
    print(arr,n);
    insertionSort(arr,n);
    print(arr,n); 
    return 0;
}