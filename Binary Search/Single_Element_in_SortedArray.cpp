//https://leetcode.com/problems/single-element-in-a-sorted-array/submissions/
//https://takeuforward.org/data-structure/search-single-element-in-a-sorted-array/
#include<bits/stdc++.h>
using namespace std;
int singleNonDuplicate(vector<int>& arr) {

    int start=0,end=arr.size()-2;

    while(start<=end){
        int mid= start + (end-start)/2;                                   //Right Half - odd-even
                                                                        // Left Half - even-odd
        if (mid % 2 == 0) {
            //Checking whether we are in right half
            if (arr[mid] != arr[mid + 1])    
                end=mid-1;                  //Shrinking the right half
            else
                start=mid+1;                //Shrinking the left half
        }
        else{
            //Checking whether we are in right half
            if (arr[mid] == arr[mid + 1]) 
                end = mid - 1;                         //Shrinking the right half
            else
                start = mid + 1;                         //Shrinking the left half
        } 
    }
    
    return arr[start];
}
int main(){
    vector<int> arr={1,1,2,3,3,4,4,8,8};
    cout<<singleNonDuplicate(arr);

    return 0;
}