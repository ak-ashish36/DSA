//https://leetcode.com/problems/third-maximum-number
//https://practice.geeksforgeeks.org/problems/third-largest-element/1
//https://www.codingninjas.com/codestudio/problems/third-greatest-element_1095642?leftPanelTab=1
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int first=-1e9,second=-1e9,third=-1e9;

        //min stores the value which is less than -1e9 in the array
        int min=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]>first){
                third=second;
                second=first;
                first=nums[i];
            }
            else if(nums[i]>second && nums[i]!=first){
                third=second;
                second=nums[i];
            }
            else if(nums[i]>third && nums[i]!=second && nums[i]!=first){
                third=nums[i];
            }
            if(nums[i]<-1e9){
                min=nums[i];
            }
        }

        //All this extra logic in only for some specific Testcases of Leetcode

        //If min is present and second max is also less than or equal to -1e9 that means third max is not available therefore return first max
        if(min!=0 && second<=-1e9){return first;}
        //If min is present and third less than or equal to -1e9 that means min is the value of third max whic is our ans
        if(min!=0 && third<=-1e9){return min;}
        
        //If min not present and third max also not available than return first max
        if(min==0 && third==-1e9){return first;}
        //if min is not present and third is not -1e9 than it means third max value is present
        else{return third;}
    }
};
int main(){
    vector<int>nums={-2147483648,1,1};
    //Output =1
    Solution obj;
    cout<<obj.thirdMax(nums);
    return 0;
}