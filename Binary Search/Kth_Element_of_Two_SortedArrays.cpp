#include<bits/stdc++.h>
using namespace std;

// Optimized Naive Approach
int solution(vector<int>& nums1, vector<int>& nums2,int key) {
    int m=nums1.size();
    int n=nums2.size();
    // int finalArray[n+m];

    int median=key;
    int i=0,j=0,k=0;

    int count=0;
    int middle;
    
    while(i<m && j<n) {
        if(count==median){break;}
      
        if(nums1[i]<nums2[j]) {

            // finalArray[k++] = nums1[i++];

            count++;
            middle =nums1[i++];
        }
        else {
            // finalArray[k++] = nums2[j++];
            count++;
            middle =nums2[j++];
        }
    }
   
    if(count<median){
        while(i<m){
            if(count==median){ break;}

            // finalArray[k++] = nums1[i++];

            count++;
            middle =nums1[i++];
        }
        while(j<n){
            if(count==median) break;

            // finalArray[k++] = nums2[j++];

            count++;
            middle =nums2[j++];
        }
    }

    // return finalArray[median-1];
    return middle;
}
double findKthSortedArrays(vector<int>& nums1, vector<int>& nums2,int key) {
    int size1=nums1.size(),size2=nums2.size();
    if(size1>size2){
        return findKthSortedArrays(nums2,nums1,key);
    }
    int start=0;
    int end=size1;
    int median=key;

    while(start<=end){
        int cut1=start+(end-start)/2;
        int cut2 =median-cut1;

        int l1 = (cut1 == 0)? INT_MIN:nums1[cut1-1];
        int r1 = (cut1 == size1)? INT_MAX:nums1[cut1];

        int l2 = (cut2 == 0)? INT_MIN:nums2[cut2-1];
        int r2 = (cut2 == size2)? INT_MAX:nums2[cut2];


        if(l1<=r2 && l2<=r1) {
            return max(l1,l2);
        }
        else if(l1>r2){
            end = cut1-1;
        } 
        else{
            start=cut1+1;
        }
    }
    return 0.0;
   
}
int main(){
    vector<int>nums1 = {100, 112, 256, 349, 770};
    vector<int>nums2 = {72, 86, 113, 119, 265, 445, 892};

    cout<<solution(nums1,nums2,7)<<endl;
    cout<<findKthSortedArrays(nums1,nums2,7)<<endl;

    return 0;
}