//https://www.codingninjas.com/codestudio/problems/615?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int merging(int arr[],int low,int mid,int high){
        int i=low;
        int j=mid+1;
        int k=low;
        int inversion_count=0;
        vector<int> merged(high+1);
        while(i<=mid && j<=high){
            if(arr[i]<arr[j]){
                merged[k++]=arr[i++];
            }
            else{
                merged[k++]=arr[j++];
                inversion_count = inversion_count + (mid+1 - i);
            }
        }
        while(i<=mid){
            merged[k++]=arr[i++];
        }
        while(j<=high){
            merged[k++]=arr[j++];
        }

        for (i = low; i<=high; i++)  {
        arr[i] = merged[i];
        }
        return inversion_count;
    }
    int mergesort(int arr[],int low,int high){
        int inversion_count=0;
        if(low<high){
            int mid =(low+high)/2;
            inversion_count += mergesort(arr,low,mid);
            inversion_count += mergesort(arr,mid+1,high);
            inversion_count += merging(arr,low,mid,high);
        }
        return inversion_count;   
    } 
};
int main(){
    int arr[]={2,5,1,3,4};
    int size=sizeof(arr)/sizeof(arr[0]);
    Solution obj;
    int x= obj.mergesort(arr,0,size-1);
    cout<<x<<endl;
    for(int i:arr){
        cout<<i;
    }
   return 0;
}