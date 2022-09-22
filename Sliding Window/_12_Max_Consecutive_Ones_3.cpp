//https://leetcode.com/problems/max-consecutive-ones-iii/
//https://practice.geeksforgeeks.org/problems/maximize-number-of-1s0905/1
//https://youtu.be/Gl-8HLvV8bc
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestOnes(vector<int>& arr, int k) {
        int n=arr.size();
        int zeroCount=0;
        int i=0,j=0;
        int ans=0;
        while(j<n){
            if(arr[j]==0){
                zeroCount++;
            }
            if(zeroCount>k){
                while(zeroCount>k){
                    if(arr[i]==0)zeroCount--;
                    i++;
                }
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};
int main(){
    vector<int>arr ={1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;
    // Output: 6    [1,1,1,0,0,1,1,1,1,1,1]
    Solution obj;
    cout<<obj.longestOnes(arr,k);
    return 0;
}