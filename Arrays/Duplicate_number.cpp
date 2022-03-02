// https://leetcode.com/problems/find-the-duplicate-number/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector < int > & arr) {
        int n = arr.size();
        int freq[n + 1] = {0};
        for (int i = 0; i < n; i++) {
            if (freq[arr[i]] == 0) {
                freq[arr[i]] += 1;
            } else {
                return arr[i];
            }
        }
        return 0;
    }
    int findDuplicateAndMissing(vector<int>& nums) {
        int sum=0,sum2=0;
        int sumSq=0,sumSq2=0;
        int x,y;
        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
            sum2=sum2+(i+1);
            sumSq=sumSq+pow(nums[i],2);
            sumSq2=sumSq2+pow((i+1),2);
        }
        int a=sum2-sum;         //x-y =a
        int b=sumSq2-sumSq;     //x^2-y^2=b;   (x+y)(x-y)=b;
                                //x+y=b/a ;  and x-y=a;
        x=(b/a+a)/2;            //x+y+x-y=a+b/a;  2x=b/a+a;    x=(b/a+a)/2;
        y=x-a;
        // cout<<a<<" "<<b<<endl;
        // x is missing element whereas y is duplicate element;
        cout<<x<<" "<<y<<endl;
        return y;
    }
};
int main(){
    vector<int> nums;
    // nums={ 4,3,6,2,1,1};
    nums={2,2,2,2,2};
    Solution obj;
    // obj.findDuplicateAndMissing(nums);
    cout<<obj.findDuplicate(nums);
   return 0;
}