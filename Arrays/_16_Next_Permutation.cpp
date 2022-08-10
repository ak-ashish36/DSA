//https://leetcode.com/problems/next-permutation/
//https://practice.geeksforgeeks.org/problems/next-permutation5226/1
//https://www.codingninjas.com/codestudio/problems/893046/
//https://youtu.be/LuLCLgMElus
#include<bits/stdc++.h>
using namespace std;
class Solution{
public : 
//T =3*O(N)  and S=O(1)
    void nextpermutation(int nums[],int size){
        int k,l;
        for(k=size-2;k>=0;k--){
            if(nums[k]<nums[k+1]){
                break;
            }
        }
        if(k<0){
            reverse(nums,nums+size);
        }
        else{
            for(l=size-1;l>k;l--){
                if(nums[l]>nums[k]){
                    break;
                }
            }
            swap(nums[k],nums[l]);
            reverse(nums+k+1,nums+size);
        }
    }
};
int main(){
    int arr[5]={1,3,5,4,2};
    int size = (sizeof(arr)/sizeof(int)); 

    Solution obj;
    obj.nextpermutation(arr,size);
    for(int i :arr){
        cout<<i<<" ";
    }
   return 0;
}