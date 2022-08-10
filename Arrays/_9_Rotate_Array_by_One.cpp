//https://leetcode.com/problems/rotate-array/
//https://practice.geeksforgeeks.org/problems/rotate-array-by-n-elements-1587115621/1
//https://www.codingninjas.com/codestudio/problems/rotate-array_1230543
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
//T : O(nk) S:O(1)
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        while(k--){
            int n=nums.size();
            int val =nums[n-1];
            for(int i=n-1;i>0;i--){
                nums[i]=nums[i-1];
            }
            nums[0]=val;
        }
    }
//T : O(n) S:O(n)
    void rotate2(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        vector<int> cpy=nums;
        for (int i = 0; i < n; i++) {
            nums[(i+k)%n] = cpy[i];
        }
    }
//T : O(n) S:O(1)
    void rotate3(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        reverse(nums.begin(),nums.end());       //7,6,5,4,3,2,1
        reverse(nums.begin(),nums.begin()+k);   //5,6,7,4,3,2,1
        reverse(nums.begin()+k,nums.end());     //5,6,7,1,2,3,4
    }
};

int main(){
    vector<int>arr={1,2,3,4,5,6,7};
    //Output: [5,6,7,1,2,3,4]
    int k=3;
    Solution obj;
    obj.rotate2(arr,k);
    for(int i:arr){
        cout<<i<<" ";
    }
    return 0;
}