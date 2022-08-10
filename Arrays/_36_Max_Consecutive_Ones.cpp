//https://leetcode.com/problems/max-consecutive-ones/
//https://www.codingninjas.com/codestudio/problems/maximum-consecutive-ones_3843993/
//https://practice.geeksforgeeks.org/problems/longest-consecutive-1s-1587115620/1
//https://youtu.be/Mo33MjjMlyA
#include<bits/stdc++.h>
using namespace std;
int findMaxConsecutiveOnes(vector<int>& nums) {
    int max_count=0,count=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==1){
            count++;
        }
        else{
            count=0;
        }
        max_count=max(count,max_count);
    }
    return max_count;
}
int main(){
    vector <int> arr{1,1,0,1,1,1};
    // cout<<findMaxConsecutiveOnes(arr);
    int n=14;
    n=n>>1;
    cout<<n;
    return 0;
}