//https://leetcode.com/problems/reverse-pairs/
//https://www.codingninjas.com/codestudio/problems/1112652
//https://youtu.be/S6rsAlj_iB4
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    int merging(vector<int>&arr,int low,int mid,int high){
        int count=0;
        int j=mid+1;
        for (int i = low; i <= mid; i++) {
            while (j <= high && arr[i] > 2LL * arr[j]) {
                 j++;
            }
            count += (j - (mid + 1));
        }
        
        int i=low;
        j=mid+1;
        int k=0;
        vector<int> merged(high-low+1);
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

        for (i = low; i <=high; i++)  {
            arr[i] = merged[i-low];
        }
        return count;
    }
    int mergesort(vector<int>&arr,int low,int high){
        int count=0;
        if(low<high){
            int mid =(low+high)/2;
            count += mergesort(arr,low,mid);
            count += mergesort(arr,mid+1,high);
            count += merging(arr,low,mid,high);
        }
        return count;   
    }
    int reversePairs(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;
        return mergesort(nums,low,high);
    }
};
int main(){
    vector<int>arr={2,4,3,5,1};
    //Output 3 [{2,1},{4,1},{5,1}]
    Solution obj;
    int x= obj.reversePairs(arr);
    cout<<x<<endl;
   return 0;
}