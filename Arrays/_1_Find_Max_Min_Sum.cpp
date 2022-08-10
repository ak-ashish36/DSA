#include <bits/stdc++.h>
using namespace std;
class Solution{
//Time Complexity: O(n)  and Space Complexity: O(1)
public:
    int max(int arr[],int n){
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            if(arr[i]>maxi){
                maxi=arr[i];
            }
        }
        return maxi;
    }
    int min(int arr[],int n){
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            if(arr[i]<mini){
                mini=arr[i];
            }
        }
        return mini;
    }
    int sum(int arr[],int n){
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        return sum;
    }
};
int main(){
    int arr[]={4,5,2,9,1,7};
    int n = sizeof(arr)/sizeof(int);
    Solution obj;
    cout<<"Max element is : "<<obj.max(arr,n)<<endl;
    cout<<"Min element is : "<<obj.min(arr,n)<<endl;
    cout<<"Sum of Array is : "<<obj.sum(arr,n)<<endl;
    return 0;
}