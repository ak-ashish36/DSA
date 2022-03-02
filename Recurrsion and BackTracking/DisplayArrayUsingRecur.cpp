#include<bits/stdc++.h>
using namespace std;
void display(int arr[],int n){
    if(n<=0){
    return;
    }
    display(arr,n-1);
    cout<<arr[n-1]<<endl;
}
void displayReverse(int arr[],int n){
    if(n<=0){
    return;
    }
    cout<<arr[n-1]<<endl;
    displayReverse(arr,n-1);
}
int main(){
    int arr[]={1,2,3,4,5};
    int n= sizeof(arr)/sizeof(int);
    // display(arr,n);
    displayReverse(arr,n);

    return 0;
}