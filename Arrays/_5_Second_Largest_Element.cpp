//https://www.codingninjas.com/codestudio/problems/second-largest-element-in-the-array_873375
//https://practice.geeksforgeeks.org/problems/second-largest3735/1
//https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array
#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    //Time : O(n+n) : S:O(1)
    int secondLargest(vector<int>arr){
        //Find the largest first
        int maxi=-1e9;
        for(int i=0;i<arr.size();i++){
            maxi=max(maxi,arr[i]);
        }
        //Find Second largest
        int smaxi=-1e9;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==maxi){continue;}
            else{
                smaxi=max(smaxi,arr[i]);
            }
        }
        return smaxi==-1e9?-1:smaxi;
    }
    //Time : O(n) : S:O(1)
    int secondLargest2(vector<int>arr){
        int maxi=INT_MIN,smaxi=INT_MIN;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>maxi){
                smaxi=maxi;
                maxi=arr[i];
            }
            else if(arr[i]>smaxi && arr[i]!=maxi){
                smaxi=arr[i];
            }
        }
        return smaxi==-1e9?-1:smaxi;
    }
};
int main(){
    vector<int>arr={5,3,1,4,6,7};
    Solution obj;
    cout<<obj.secondLargest2(arr);
    return 0;
}