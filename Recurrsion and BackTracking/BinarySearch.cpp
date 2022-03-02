#include<bits/stdc++.h>
using namespace std;
int binarySearch(vector<int>arr,int target,int s, int e){
    if(s>e){
        return -1;
    }
    int mid=s+(e-s)/2;
    if(arr[mid]==target){
        return mid;
    }
    else if(arr[mid]>target){
        return binarySearch(arr,target,s,mid-1);
    }
    else{
        return binarySearch(arr,target,mid+1,e);

    }
}

int main(){
    vector <int> arr={1,2,3,4,5,6,7,8};
    int target =8;
    cout<<"Index of "<<target<<" is :"<<binarySearch(arr,target,0,arr.size()-1);

    return 0;
}