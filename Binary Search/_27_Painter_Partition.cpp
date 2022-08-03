//https://practice.geeksforgeeks.org/problems/the-painters-partition-problem1535/1
//https://www.codingninjas.com/codestudio/problems/painter-s-partition-problem_1089557
//Same Logic as Previous Problem (Allocate_Minimun_no_of_Pages)
#include<bits/stdc++.h>
using namespace std;
bool isPossible(vector<int>&arr,int painters,int time) {
    int count=1;
    int currSum=0;
    for(int i=0;i<arr.size();i++){
        if(currSum+arr[i]<=time){//If curr page sum is less than number of pages than we increase the pagesum
            currSum+=arr[i];
        }else{
            count++;
            currSum=arr[i];
            if(count>painters || currSum>time ){
                return false;
            }
        }
    }
    return true; 
}
int paint(vector<int>&arr,int k) {
    if (k > arr.size()) return -1;
    int start=arr[0],end=0;
    int result=-1;
    for(int i=0;i<arr.size();i++){
        start=max(start,arr[i]);
        end=end+arr[i];
    }
    while(start<=end){
        int mid = start + (end-start)/2;
        if (isPossible(arr,k,mid)){
            result=mid;
            end=mid-1;
        }else{
            start=mid+1;
        }
    }
    return start;
}
int main(){
    vector<int>arr={10,20,30,40};
    cout<<paint(arr,2);
    return 0;
}