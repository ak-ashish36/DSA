#include<bits/stdc++.h>
using namespace std;

int maxOfArray(int arr[],int size,int index=0){
    if(index==size-1){
        return arr[index];
    }
    
    int max_in_next=maxOfArray(arr,size,index+1);

    if(max_in_next>arr[index]){
        return max_in_next;
    }
    else{
        return arr[index];
    }

}
int main(){
   int arr[]={1,2,9,4,5};
    int n= sizeof(arr)/sizeof(int);
    cout<<maxOfArray(arr,n); 
    return 0;
}