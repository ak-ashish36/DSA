#include<bits/stdc++.h>
using namespace std;
vector<int> solution(vector<int>&arr,int k, int x){
    vector<int>ans;
    priority_queue<pair<int,int>> maxH;

    for(int i=0;i<arr.size();i++){
        maxH.push({abs(arr[i]-x),arr[i]});
        if(maxH.size()>k){
            maxH.pop();
        }
    }
    while(!maxH.empty()){
           ans.push_back(maxH.top().second);
           maxH.pop();
    }
    return ans;
}
int main(){
    vector<int>arr={1,2,3,4,5};
    vector<int>ans=solution(arr,4,3);

    for(int i:ans){
        cout<<i<<" ";
    }

    return 0;
}