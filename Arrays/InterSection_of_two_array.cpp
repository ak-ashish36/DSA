#include<bits/stdc++.h>
using namespace std;

vector<int>Union(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int>s;

    for(int i:nums1){
        s.insert(i);
    }
    for(int i:nums2){
        s.insert(i);
    }
    vector<int>ans;
    for(auto it :s){
        ans.push_back(it);
    }
    return ans;     
}
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int>s;
    for(int i:nums1){
        s.insert(i);
    }
    vector<int>ans;
    for(int i: nums2){
        if(s.find(i)!=s.end()){
            ans.push_back(i);
            s.erase(i);
        }
    }
    return ans;     
}
int main(){
    vector<int>arr1={1,2,2,1}; 
    vector<int>arr2={2,2}; 
    vector<int>ans=Union(arr1,arr2);

    for(int i:ans){
        cout<<i<<" ";
    }
     
    return 0;
}