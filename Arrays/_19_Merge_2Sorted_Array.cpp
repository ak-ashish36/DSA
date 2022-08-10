//https://leetcode.com/problems/merge-sorted-array/
//https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1
//https://www.codingninjas.com/codestudio/problems/1214628/
//https://youtu.be/hVl2b3bLzBw
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
//T= O(nlogn) and S=O(n)
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
    }
//T= O(m*nlogn) and S=O(1)
    void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m==0){
            nums1=nums2; 
            return; 
        }
        if(n==0)
            return; 
        for(int i=0;i<m;i++){
            if(nums1[i]>nums2[0]){
                swap(nums1[i],nums2[0]);
            }
            //Sort nums2 (Preffer Insertion Sort)
            int j,first = nums2[0];
            for (j = 1; j < n && nums2[j] < first; j++) {
                nums2[j-1] = nums2[j];
            }
            nums2[j-1] = first;
        }

        nums1.erase(nums1.begin()+m,nums1.end());
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
    }
//T= O(m+n) and S=O(1)
    void merge3(vector<int>& nums1, int m, vector<int>& nums2, int n) {

    }
};
int main(){
    vector<int> arr1={1,2,3,0,0,0};
    vector<int> arr2={2,5,6};
    int x=3,y=3;
    Solution obj;
    obj.merge2(arr1,x,arr2,y);
    for(auto i: arr1){
        cout<<i<<",";
    }
    return 0;
}