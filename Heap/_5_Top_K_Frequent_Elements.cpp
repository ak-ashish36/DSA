#include<bits/stdc++.h>
using namespace std;
vector<int> solution(vector<int>&arr,int k){
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
int main(){
    vector<int>arr={1,1,1,2,2,3}; 

    vector<int>ans=solution(arr,2);

    for(int i:ans){
        cout<<i<<" ";
    }
    return 0;
}