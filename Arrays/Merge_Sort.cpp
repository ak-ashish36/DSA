//https://www.codingninjas.com/codestudio/problems/615?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    void merging(int arr[],int low,int mid,int high){
        int i=low;
        int j=mid+1;
        int k=low;
        int merged[10];
        while(i<=mid && j<=high){
            if(arr[i]<arr[j]){
                merged[k++]=arr[i++];
            }
            else{
                merged[k++]=arr[j++];
            }
        }
        while(i<=mid){
            merged[k++]=arr[i++];
        }
        while(j<=high){
            merged[k++]=arr[j++];
        }

        for (i = low; i < k; i++)  {
        arr[i] = merged[i];
        }
    }
    void mergesort(int arr[],int low,int high){
        
        if(low<high){
        int mid =(low+high)/2;
        mergesort(arr,low,mid);
        mergesort(arr,mid+1,high);
        merging(arr,low,mid,high);
        }
    } 
};
int main(){
    int arr[6]={3,5,7,1,9,4};
    Solution obj;
    obj.mergesort(arr,0,5);
    for (int i = 0; i < 6; i++)
    {
        cout<<arr[i]<<" ";
    }

   return 0;
}