#include<bits/stdc++.h>
using namespace std;
vector<int> frequencySort(vector<int>&arr){
    unordered_map<int,int>mpp;
    for(int i :arr){
        mpp[i]++;
    }
    
    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > minH;

    for(auto it : mpp) {
        minH.push({it.second,it.first});
    }
    vector<int> ans;
    while(!minH.empty()){
        for(int i=0;i<minH.top().first;i++){
            ans.push_back(minH.top().second);
        }
        minH.pop();
    }
    return ans;
}

int main(){
    vector<int>arr={2,3,1,3,2}; 

    vector<int>ans=frequencySort(arr);

    for(int i:ans){
        cout<<i<<" ";
    }
    return 0;
}