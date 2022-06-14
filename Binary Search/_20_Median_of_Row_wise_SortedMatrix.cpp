#include<bits/stdc++.h>
using namespace std;


int countSmallerThanEqualto(int arr[],int start,int end ,int target){
    while(start<=end){
        int mid = start + (end-start)/2;
        if(arr[mid]<=target){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return start;
}
int findMedian(int arr[][3],int row,int col){
    int start=0;
    int end=1e9;

    int median=(row*col)/2;

    while(start<=end){
        int mid = start + (end-start)/2;
        int count=0;
        for(int i=0;i<row;i++){
            count +=countSmallerThanEqualto(arr[i],0,col-1,mid);
        }
        if(count>median){
            end=mid-1;
        }
        else{   //count<=median
            start=mid+1;
        }
    }
    return start;

}
int main(){
    // int arr[][5]={{1,2,6,6,10},
    //              {2,4,4,5,7},
    //              {2,5,5,6,6}};

    int arr[][3]={{1,3,5},
                 {2,6,9},
                 {3,6,9}};            

    int col=sizeof(arr[0])/sizeof(int);
    int row=sizeof(arr)/sizeof(int)/col; 
    cout<<findMedian(arr,row,col)<<endl;
    return 0;
}
