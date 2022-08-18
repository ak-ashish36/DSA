//https://leetcode.com/problems/sort-array-by-increasing-frequency/
//https://practice.geeksforgeeks.org/problems/sorting-elements-of-an-array-by-frequency/0
//https://youtu.be/hLR5aMzYGGk
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
//Sort by Increasing frequency and if same freq sort in ascending order
    vector<int> frequencySort1(vector<int>& arr) {
        unordered_map<int,int>mpp;
        for(int i :arr){mpp[i]++;}

        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > minH;

        for(auto it : mpp) {
            minH.push({it.second,it.first});
        }
        vector<int> ans;
        while(!minH.empty()){
            int num = minH.top().second;
            int freq= minH.top().first;
            minH.pop();

            while(freq--){
                ans.push_back(num);
            }
        }
        return ans;
    }
//Sort by Descreasing frequency and if same freq sort in ascending order //GFG
    vector<int> frequencySort2(vector<int>& arr) {
        unordered_map<int,int>mpp;
        for(int i :arr){mpp[i]++;}

        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > minH;

        for(auto it : mpp) {
            minH.push({-it.second,it.first}); //highest freq will become negative to become top value in minHeap
        }
        vector<int> ans;
        while(!minH.empty()){
            int num = minH.top().second;
            int freq= -minH.top().first;
            minH.pop();

            while(freq--){
                ans.push_back(num);
            }
        }
        return ans;
    }
//Sort by Increasing frequency and if same freq sort in descending order -Leetcode
    vector<int> frequencySort3(vector<int>& arr) {
        unordered_map<int,int>mpp;
        for(int i :arr){mpp[i]++;}

        priority_queue<pair<int,int>> maxH;

        for(auto it : mpp) {
            maxH.push({-it.second,it.first}); //highest freq will become negative to become lowest value in maxHeap
        }
        vector<int> ans;
        while(!maxH.empty()){
            int num = maxH.top().second;
            int freq= -maxH.top().first;
            maxH.pop();

            while(freq--){
                ans.push_back(num);
            }
        }
        return ans;
    }
};

int main(){
    vector<int>arr={2,3,1,3,2}; 
    Solution obj;
    vector<int>ans=obj.frequencySort3(arr);
    for(int i:ans){
        cout<<i<<" ";
    }
    return 0;
}