//https://www.codingninjas.com/codestudio/problems/920321?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
#include<bits/stdc++.h>
using namespace std;
// T=O(n2), S=O(1)
int LongestSubsetWithZeroSum(vector<int>& nums) {
    int max=0;
    for(int i=0;i<nums.size();i++){
        int sum=0;
        for(int j=i;j<nums.size();j++){
            sum += nums[j];
            if(sum==0){
                if((j-i+1)>max){
                    max=j-i+1;
                }
            }
        }
    }
    return max;
}
// T=O(n), S=O(n)
int LongestSubsetWithZeroSum2(vector<int>& nums) {
    unordered_map<int,int>mpp;
    int sum=0;
    int max=0;
    for(int i=0;i<nums.size();i++){
        sum+=nums[i];
        if(sum==0){
            max=i+1;
        }
        else{
            if(mpp.find(sum)!=mpp.end()){
                int maxFound=i-mpp[sum];
                if(maxFound>max){
                    max=maxFound;
                }
            }
            mpp[sum]=i;
        }
    }
    return max;
}
int main(){
    vector<int> arr={1,3,-1,4,-4};
    cout<<LongestSubsetWithZeroSum2(arr);
    
   return 0;
}