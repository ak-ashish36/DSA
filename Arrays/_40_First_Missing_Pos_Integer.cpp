//https://leetcode.com/problems/first-missing-positive/
//https://www.interviewbit.com/problems/first-missing-integer/
//https://youtu.be/aBhla9jSAeg
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums){
        int maxi=-1e9;
        set<int>set;
        for(int i=0;i<nums.size();i++){
            set.insert(nums[i]);
            maxi=max(maxi,nums[i]);
        }
        
        for(int i=1;i<=maxi;i++){
            
            if(set.find(i)!=set.end()){
                continue;
            }else{
                return i;
            }
        }
        if(maxi<=0){return 1;}
        return maxi+1;
    }
};
int main(){
    vector<int>arr={7,8,9,11,12};
    Solution obj;
    cout<<obj.firstMissingPositive(arr);
    return 0;
}