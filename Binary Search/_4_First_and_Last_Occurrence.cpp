//https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
#include<bits/stdc++.h>
using namespace std;
class Solution{
    int firstOccurrence(vector<int>& arr,int target,int start,int end){
        int result=-1;
        while(start<=end){
            int mid=start + (end-start)/2;
            if(arr[mid]==target){
                result=mid;
                end=mid-1;
            }
            else if(arr[mid]>target){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return result;
    }
    int lastOccurrence(vector<int>& arr,int target,int start,int end){
        int result=-1;
        while(start<=end){
            int mid=start + (end-start)/2;
            if(arr[mid]==target){
                result=mid;
                start=mid+1;
            }
            else if(arr[mid]>target){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return result;
    }
int firstOccurrenceRec(vector<int>& arr,int target,int start,int end){
    if(start>end){
        return -1;
    }
    int mid= start + (end - start) / 2;

    if (arr[mid] == target && (mid == 0 || target > arr[mid - 1])){
        return mid;
    }
    else if(arr[mid]<target){
        return firstOccurrenceRec(arr,target,mid+1,end);
    }
    else{
        return firstOccurrenceRec(arr,target,start,mid-1);
    }  
}
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans(2,-1);
        ans[0]=firstOccurrence(nums,target,0,nums.size()-1);
        ans[1]=lastOccurrence(nums,target,0,nums.size()-1);
        
        return ans;

    }
};

int main(){
    vector<int>arr={5,7,7,8,8,10};
    Solution obj;
    vector<int>ans=obj.searchRange(arr,8);

    cout<<"First Occurence: "<<ans[0]<<endl;
    cout<<"Last Occurence: "<<ans[1]<<endl;
    return 0;
}