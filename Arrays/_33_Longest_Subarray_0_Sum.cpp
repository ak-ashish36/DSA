//https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1
//https://www.codingninjas.com/codestudio/problems/920321/
//https://youtu.be/xmguZ6GbatA
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    // T=O(n2), S=O(1)
    int LongestSubsetWithZeroSum(vector<int>& nums) {
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            int sum=0;
            for(int j=i;j<nums.size();j++){
                sum += nums[j];
                if(sum==0){
                    maxi=max(maxi , j-i+1);
                }
            }
        }
        return maxi;
    }
// T=O(n), S=O(n)
    int LongestSubsetWithZeroSum2(vector<int>& nums) {
        unordered_map<int,int>mpp;
        int sum=0,maxi=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum==0){
                maxi=i+1;
            }
            //Intution : sum of arr{1,3,-1}=3 and sum of arr{1,3,-1,4,-4} =3,
            //this means sum of{4,-4}=0 to satisfy the above condition
            else{
                if(mpp.find(sum)!=mpp.end()){//Sum found in hashmap
                    int maxFound=i-mpp[sum];
                    maxi=max(maxi,maxFound);
                }else{
                    mpp[sum]=i;
                }
            }
        }
        return maxi;
    }
};
int main(){
    vector<int> arr={1,3,-1,4,-4};
    //Output= 2 {4,-4}
    Solution obj;
    cout<<obj.LongestSubsetWithZeroSum(arr);
   return 0;
}