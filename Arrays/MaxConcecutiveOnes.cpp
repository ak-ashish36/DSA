//https://leetcode.com/problems/max-consecutive-ones/
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
    cout<<findMaxConsecutiveOnes(arr);
    return 0;
}