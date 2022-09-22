//https://practice.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1
//https://youtu.be/KtpqeN0Goro
#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int maximumSumSubarray(int k, vector<int>&arr){
        int n=arr.size();
        int maxi=-1e9;
        int i=0,j=0;
        int sum=0;
        for(j=0;j<n;j++){
            sum+=arr[j];
            if(j-i+1 == k){
                maxi=max(maxi,sum);
                sum=sum-arr[i];
                i++;
            }
        }
        return maxi;
    }
};
int main(){
    vector<int>arr={100,200,300,400};
    int k=2;
    //Output =700
    Solution obj;
    cout<<obj.maximumSumSubarray(k,arr);
    return 0;
}