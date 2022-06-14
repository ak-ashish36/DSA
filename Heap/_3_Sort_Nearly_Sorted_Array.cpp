#include<bits/stdc++.h>
using namespace std;
vector<int> solution(vector<int>arr,int k){
    priority_queue <int, vector<int>, greater<int> > minH;
    vector<int>ans;
    for(int i=0;i<arr.size();i++){
        minH.push(arr[i]);
        if(minH.size()>k){
            ans.push_back(minH.top());
            minH.pop();
        }
    }
    while(!minH.empty()){
           ans.push_back(minH.top());
           minH.pop();
    }
    return ans;
}
int main(){
    vector<int>arr={6,5,3,2,8,10,9};
    vector<int>ans=solution(arr,4);

    for(int i:ans){
        cout<<i<<" ";
    }

    return 0;
}