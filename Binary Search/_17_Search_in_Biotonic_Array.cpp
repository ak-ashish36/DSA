#include<bits/stdc++.h>
using namespace std;

int binarySearchInc(int arr[],int start,int end,int target){
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
int binarySearchDec(int arr[],int start,int end,int target){

    while(start<=end){
        int mid=start + (end-start)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]>target){
            start=mid+1;
        }
        else{
            end=mid-1;

        }
    }
    return -1;
}

int peek(int arr[],int start,int end,int target){
    int size=end+1;
    if(size==1){
        if(arr[0]==target){
            return 0;
        }else{return -1;}
    }
    int maxElement;
    while(start<=end){
        int mid=start + (end-start)/2;
        if(mid >0 && mid<size-1){
            if(arr[mid-1]<arr[mid] && arr[mid]>arr[mid+1]){
                maxElement=mid;
                break;
            }
            else if(arr[mid-1]>arr[mid]){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
    
        else if(mid==0){
            if(arr[mid]>arr[mid+1]){
                maxElement=mid;
                break;
            }else{
                maxElement=mid+1;
                break;
            }
        }
        else if(mid==size-1){
            if(arr[mid]>arr[mid-1]){
                maxElement=mid;
                break;
            }else{
                maxElement=mid-1;
                break;
            }
        }
    }

    int x= binarySearchInc(arr,0,maxElement-1,target);
    int y= binarySearchDec(arr,maxElement,size-1,target);
   
    return max(x,y);

}


int main(){
    int arr[]={1,3,8,12,4,2};
    int size=sizeof(arr)/sizeof(int);
    cout<<peek(arr,0,size-1,4);
    return 0;
}