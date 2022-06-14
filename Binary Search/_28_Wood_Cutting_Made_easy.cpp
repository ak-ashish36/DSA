//https://youtu.be/W-UalzYVEiQ
#include<bits/stdc++.h>
using namespace std;
int findHeight(vector<int> &arr, int B) {
    int start = 0;
    int end = 0;
    for (int i = 0; i < arr.size(); i++) {
        end=max(end,arr[i]);
    }
    int ans=-1;
    while(start<=end){
        int mid = start + (end-start)/2;
        int wood=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]-mid>0){
                wood+=arr[i]-mid;
            }
        }
        if(wood>=B){
            start=mid+1;
            ans=mid;
        }
        else{
            end=mid-1;
        }
    }
    return ans;
}
int main(){
    vector<int>arr{20, 15, 10, 17};
    int B =7 ;
    cout<<findHeight(arr,B);
    return 0;
}