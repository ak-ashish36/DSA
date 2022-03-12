#include<bits/stdc++.h>
using namespace std;

int binarySerach(int arr[],int size,int target){
    if(size==1){
        if(arr[0]==target){
            return 0;
        }else{
            return -1;
        }
    }

    int start=0,end=size-1;

    if(arr[0]<arr[1]){
        //use normal binary search
    }
    else{
        // use binary search on reverse sorted array
    }

}
int main(){ 
    return 0;
}