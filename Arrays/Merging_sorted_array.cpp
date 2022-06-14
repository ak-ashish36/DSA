// https://leetcode.com/problems/merge-sorted-array/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector <int> mergedArr;
        for(int i=0;i<m;i++){
            mergedArr.push_back(nums1[i]);
        }
        for(int i=0;i<n;i++){
            mergedArr.push_back(nums2[i]);
        }
        sort(mergedArr.begin(),mergedArr.end()); 
        nums1.swap(mergedArr);
        for(auto r: nums1){
        cout<<r<<",";
        }
    }
    //Better Omptimization with less space
    void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m==0){
            nums1=nums2; 
            return; 
        }
        if(n==0)
            return; 
        int x=0;
        for(int i=0;i<m;i++){
            if(nums1[i]>nums2[x]){
                swap(nums1[i],nums2[x]);
            }
            sort(nums2.begin(),nums2.end());

        }
        nums1.erase(nums1.begin()+m,nums1.end());
      
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        for(auto r: nums1){
        cout<<r<<",";
        }
    }

};
int main(){
    vector<int> arr1={1,2,3,0,0,0};
    vector<int> arr2={2,5,6};
    int x=3,y=3;
    Solution obj;
    // obj.merge(arr1,x,arr2,y);

    obj.merge2(arr1,x,arr2,y);
    return 0;
}