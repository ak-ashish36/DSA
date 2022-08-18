#include<bits/stdc++.h>
//https://leetcode.com/problems/top-k-frequent-elements/
//https://practice.geeksforgeeks.org/problems/top-k-frequent-elements-in-array/1
//https://www.codingninjas.com/codestudio/problems/k-most-frequent-elements_3167808
//https://youtu.be/7VoJn544QrM
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& arr, int k) {
        unordered_map<int,int>mpp;
        for(int i :arr){
            mpp[i]++;
        }
    
        priority_queue<pair<int,int>> maxH;
        for(auto it : mpp) {
            maxH.push({it.second,it.first});
        }
        vector<int> ans;
        while(k--) {
            ans.push_back(maxH.top().second);
            maxH.pop();
        }
        return ans;
    }
};
int main(){
    vector<int>arr={1,1,1,2,2,3}; 
    Solution obj;
    vector<int>ans=obj.topKFrequent(arr,2);
    for(int i:ans){
        cout<<i<<" ";
    }
    return 0;
}