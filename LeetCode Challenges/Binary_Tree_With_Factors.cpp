//https://leetcode.com/problems/binary-trees-with-factors/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    const int mod = 1e9 + 7;
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        unordered_map<int,long long>mpp;
        
        for(int i=0;i<arr.size();i++){
            mpp[arr[i]]=1;
        }
        sort(arr.begin(),arr.end());
        
        for(int i=1;i<arr.size();i++){
            long long noOfWays=1;     //Already have one way
            for(int j=0;j<i;j++){
                if(arr[i]%arr[j]==0){//if curr num is divisible by prev nums in array than there is possibility of find second 2nd num 
                    int num1=arr[j];
                    int num2=arr[i]/arr[j];
                    if(mpp.find(num2)!=mpp.end()){
                        noOfWays += mpp[num1]*mpp[num2];
                    }
                }
            }
            mpp[arr[i]]=noOfWays;
        }
        
        int count=0;
        for(auto it :mpp){
            count = (count+(it.second))%mod;
        }
        return count;
    }
};

int main(){
    vector<int>arr={2,4,5,10};
    //Output = 7 [{2},{4},{5},{10},{4,2,2},{10,2,5},{10,5,2}]
    Solution obj;
    cout<<obj.numFactoredBinaryTrees(arr);
    return 0;
}