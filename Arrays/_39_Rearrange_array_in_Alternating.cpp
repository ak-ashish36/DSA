//https://leetcode.com/problems/rearrange-array-elements-by-sign/submissions/
//https://www.codingninjas.com/codestudio/problems/rearrange-alternatively_873851
#include<bits/stdc++.h>
using namespace std;
class Solution{
private:
    void rightrotate(vector<int>&arr,int outofplace, int cur){
        int tmp = arr[cur];
        for (int i = cur; i > outofplace; i--)
            arr[i] = arr[i - 1];
        arr[outofplace] = tmp;
    }
public:
// T= O(n^2)  S= O(1)
    void rearrangeArray(vector<int>&arr){
        int n=arr.size();
        int wrongIndex=-1;

        for(int i=0;i<n;i++){
            // Find Wrong Index in array
            if(wrongIndex==-1){
                if( (arr[i]<0 && i%2==0) || (arr[i]>=0 && i%2==1)){ //if neg is at even index or pos is at odd index
                    wrongIndex=i;
                }
            }
            else{
                if( (arr[wrongIndex]>=0 && arr[i]<0) || (arr[wrongIndex]<0 && arr[i]>=0) ){
                    rightrotate(arr,wrongIndex,i);
                    if (i - wrongIndex >= 2) wrongIndex+=2;
                    else wrongIndex = -1;
                }
            }
        }
    }
// T= O(n)  S= O(2n)
    vector<int> rearrangeArray2(vector<int>&arr){
        int n=arr.size();
        vector<int>pos,neg;
        for(int i=0;i<n;i++){
            if(arr[i]<0){
                neg.push_back(arr[i]);
            }
            else{
                pos.push_back(arr[i]);
            }
        }
    
        int i=0,j=0,k=0;
        // Arranging in (+,-) fashion
        while(j<pos.size() && k<neg.size()){
            if(i==0 || arr[i-1]<0){
                arr[i++]=pos[k++];
            }
            if(arr[i-1]>0){
                arr[i++]=neg[j++];
            }
        }
        while(j<pos.size()){
            arr[i++]=pos[j++];
        }
        while(k<neg.size()){
            arr[i++]=pos[k++];
        }
        return arr;
    }
};
int main(){
    vector<int>arr = {-5,-2,5,2,4,7,1,8,0,-8};
    Solution obj;
    obj.rearrangeArray2(arr);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}