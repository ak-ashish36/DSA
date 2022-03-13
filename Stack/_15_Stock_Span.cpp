#include<bits/stdc++.h>
using namespace std;
vector<int> nearestGreaterLeftIndex(vector<int>arr){
    vector<int>ans;
    stack<pair<int,int>>s;

    for(int i=0;i<arr.size();i++){
        if(s.empty()){
            ans.push_back(-1);
        }
        else if(s.top().first>arr[i]){
            ans.push_back(s.top().second);
        }

        else if(s.top().first<=arr[i]){
            while(!s.empty() && s.top().first<=arr[i]){
                s.pop();
            }
            if(s.empty())
                ans.push_back(-1);
            else
                ans.push_back(s.top().second);
        }
        s.push(make_pair(arr[i],i));
    }

    for(int i=0;i<ans.size();i++){
        ans[i]=i-ans[i];
    }
    return ans;
}
int main(){
    vector<int>arr={100,80,60,70,60,75,85};

    vector<int> ans=nearestGreaterLeftIndex(arr);

    for(int i:ans){
        cout<<i<<" ";
    }
     
     
    return 0;
}