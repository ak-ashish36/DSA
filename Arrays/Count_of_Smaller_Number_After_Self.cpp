#include<bits/stdc++.h>
using namespace std;
class Solution {  
      
    void merging(vector<pair<int,int>>&arr, int low, int mid, int high, vector<int>&counts){
        
        int i=low;
        int j=mid+1;
        int k=0;
        vector<pair<int,int>>merged(high-low+1);
        
        while(i<=mid && j<=high){
            if(arr[i].first<=arr[j].first){
                merged[k++]=arr[j++];
            }
            else{
                counts[arr[i].second]+=high-j+1;
                merged[k++]=arr[i++];
            }
        }
        while(i<=mid){
            merged[k++]=arr[i++];
        }
        while(j<=high){
            merged[k++]=arr[j++];
        }

        for (i = low; i<=high; i++)  {
            arr[i] = merged[i-low];
        }
    }  
    void mergeSort(vector<pair<int,int>>&arr,int low,int high,vector<int>&counts){   
        if(low>=high)return;

        int mid =(high+low)/2;
        mergeSort(arr,low,mid,counts);
        mergeSort(arr,mid+1,high,counts);
        merging(arr,low,mid,high,counts);   
    }

    public:
    vector<int> countSmaller(vector<int>& nums){

        vector<pair<int,int>>arr;
        vector<int>counts(nums.size(),0);
        
        for(int i=0;i<nums.size();i++){
            arr.push_back({nums[i],i});
        }
        
        mergeSort(arr,0,nums.size()-1,counts);
        
        return counts;
    }
};
int main(){
    vector<int>nums={5,2,6,1};
    Solution obj;
    vector<int>ans=obj.countSmaller(nums);

    for(int i :ans){
        cout<<i<<" ";
    }
    return 0;
}