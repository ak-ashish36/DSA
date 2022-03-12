//https://takeuforward.org/data-structure/median-of-two-sorted-arrays-of-different-sizes/
#include<bits/stdc++.h>
using namespace std;
//Optimised Naive approached
float median(vector<int>& nums1, vector<int>& nums2) {
    int m=nums1.size();
    int n=nums2.size();
    // int finalArray[n+m];

    int median=(n+m+1)/2;
    int i=0,j=0,k=0;

    int count=0;
    int middle=0;
    int middle_next=0;
    
    while(i<m && j<n) {
        if(count==median){break;}
      
        if(nums1[i]<nums2[j]) {
            // finalArray[k++] = nums1[i++];

            count++;
            middle =nums1[i++];
            if((m+n)%2==0){
                if(i<m && nums1[i]<nums2[j]){middle_next=nums1[i];}
                else{middle_next=nums2[j];}
            }
        }
        else {
            // finalArray[k++] = nums2[j++];

            count++;
            middle =nums2[j++];
            if((m+n)%2==0){
                if(j<n && nums2[j]<nums1[i]){middle_next=nums2[j];}
                else{middle_next=nums1[i];}
            }
        }
    }
   
    if(count<median){
        if(i<m) {
            while(i<m){
                if(count==median){ break;}

                // finalArray[k++] = nums1[i++];
                count++;
                middle =nums1[i++];
                if(i<m)
                    middle_next=nums1[i];
            }
        }
        if(j<n) {
            while(j<n){
                if(count==median) break;

                // finalArray[k++] = nums2[j++];

                count++;
                middle =nums2[j++];
                if(j<n)
                    middle_next=nums2[j];
            }
        }
    }

    if((n+m)%2==1){ 
        // return finalArray[median-1];
        return middle;
    }
    // else return ((float)finalArray[median-1]+(float)finalArray[median])/2;
    else return ((float)middle+(float)middle_next)/2;
}

// Binary Search Approach
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int size1=nums1.size(),size2=nums2.size();
    if(size1>size2){
        return findMedianSortedArrays(nums2,nums1);
    }
    int start=0;
    int end=size1;
    int median=(size1+size2+1)/2;

    while(start<=end){
        int cut1=start+(end-start)/2;
        int cut2 =median-cut1;

        int l1 = (cut1 == 0)? INT_MIN:nums1[cut1-1];
        int r1 = (cut1 == size1)? INT_MAX:nums1[cut1];

        int l2 = (cut2 == 0)? INT_MIN:nums2[cut2-1];
        int r2 = (cut2 == size2)? INT_MAX:nums2[cut2];

        // int l1 = nums1[cut1-1];
        // int r1 = nums1[cut1];

        // int l2 = nums2[cut2-1];
        // int r2 = nums2[cut2];

        if(l1<=r2 && l2<=r1) {
            // if array's total size is odd than middle
            if((size1+size2)%2 != 0)
                return max(l1,l2);
            else 
                return (max(l1,l2)+min(r1,r2))/2.0;
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
int main() {
    vector<int>nums1 = {2,3,6,7,9};
    vector<int>nums2 = {1,4,8,10};
    cout<<"The Median of two sorted arrays is "<<fixed<<setprecision(5)<<findMedianSortedArrays(nums1,nums2)<<endl;

    cout<<"The median of two sorted array is "<<fixed<<setprecision(5)<<median(nums1,nums2)<<endl;
    return 0;
}