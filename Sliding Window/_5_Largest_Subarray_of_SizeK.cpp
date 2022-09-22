//https://practice.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1
#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
//T=O(n2)
    int lenOfLongSubarr(vector<int>&arr, int k){ 
        int n=arr.size();
        int maxi=0;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=arr[j];
                if(sum==k){
                    maxi=max(maxi,j-i+1);
                }
            }
        }
        return maxi;
    } 
//Optimised T=O(n) This sol will not work for negative numbers
    int lenOfLongSubarr2(vector<int>&arr, int k){ 
        int n=arr.size();
        int maxi=0;
        int sum=0;
        int i=0,j=0;
        for(j=0;j<n;j++){
            sum+=arr[j];
            if(sum==k){
                maxi=max(maxi,j-i+1);
            }
            if(sum>k){
                while(sum>k){
                    sum-=arr[i++];
                    if(sum==k){
                        maxi=max(maxi,j-i+1);
                    }
                }
            }
        }
        return maxi;
    }
//Best Soln Using Map T=O(n) S=O(n)
int lenOfLongSubarr3(vector<int>&arr, int k){ 
        int n=arr.size();
        unordered_map<int,int>mpp;
        int maxi=0;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum==k) { 
                maxi=max(maxi,i+1);
            }
            if(mpp.find(sum-k)!=mpp.end()){
                maxi=max(maxi,i-mpp[sum-k]);
            }
            if(mpp.find(sum)==mpp.end()){
                mpp[sum]=i;
            }
        }
        return maxi;
    }
};
int main(){
    vector<int>arr={10, 5, 2, 7, 1, 9};
    int k=15;
    //Output = 4{5,2,7,1}
    Solution obj;
    cout<<obj.lenOfLongSubarr3(arr,k);
    return 0;
}