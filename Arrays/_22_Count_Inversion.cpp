//https://www.codingninjas.com/codestudio/problems/count-inversions_615
//https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1
//https://youtu.be/kQ1mJlwW-c0
#include<bits/stdc++.h>
using namespace std;

class Solution {
    int merging(int arr[],int low,int mid,int high){
        int i=low;
        int j=mid+1;

        int k=0;
        int count=0;
        vector<int> merged(high-low+1);
        
        while(i<=mid && j<=high){
            if(arr[i]<=arr[j]){
                merged[k++]=arr[i++];
            }
            else{       
                merged[k++]=arr[j++];
                count = count + (mid+1 - i);
            }
        }
        while(i<=mid){
            merged[k++]=arr[i++];
        }
        while(j<=high){
            merged[k++]=arr[j++];
        }
        k=0;
        for (i = low; i<=high; i++)  {
            arr[i] = merged[k++];
        }
        return count;
    }
    int mergesort(int arr[],int low,int high){
        int count=0;
        if(low<high){
            int mid =(low+high)/2;
            count += mergesort(arr,low,mid);
            count += mergesort(arr,mid+1,high);
            count += merging(arr,low,mid,high);
        }
        return count;   
    }
public:
    int countInversions(int arr[], int n){
        return mergesort(arr,0,n-1);
    }
};
int main(){
    int arr[]={2,5,1,3,4};
    int size=sizeof(arr)/sizeof(arr[0]);
    //Output = 4 [{2,1},{5,1}{5,3}{5,4}]
    Solution obj;
    int x= obj.countInversions(arr,size);
    cout<<x<<endl;
   return 0;
}