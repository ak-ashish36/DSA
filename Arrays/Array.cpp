#include<bits/stdc++.h>
using namespace std;
void print1d(int arr[],int n){
    for(int i=0; i<n;i++){
       cout<<arr[i]<<" ";
   }
   cout<<endl;
}
void print2d(int arr[2][3]){  
   for(int i=0;i<2;i++){
       for(int j=0;j<3;j++){
           cout<<arr[i][j]<<" ";
       }
       cout<<endl;
   }
   cout<<endl;
}
int main(){
   // int arr[5];
   // int arr[5]={};
   // int arr[] ={1,2,3,4};
   // int n=sizeof(arr)/sizeof(int);

   int* arr = new int[5];   //Dynamically Allocating array of size 5 with garbage value
   // int* arr = new int[5]{};   //Dynamically Allocating array of size 5 initializing with 0
   // int n=sizeof(*arr)/sizeof(int);
   // print1d(arr,n);

   // int arr[2][3]={{1,2,3},{4,5,6}};
   // int arr[2][3]={{-1,3}};
   // print2d(arr);

   return 0;
}