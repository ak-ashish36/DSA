#include<bits/stdc++.h>
using namespace std;
vector<int> nearestSmallerL(vector<int>arr){
    vector<int>ans;
    stack<int>s;
    for(int i=0;i<arr.size();i++){
        if(s.empty()){
            ans.push_back(-1);
        }
        else if(s.top()<arr[i]){
            ans.push_back(s.top());
        }

        else if(s.top()>=arr[i]){
            while(!s.empty() && s.top()>=arr[i]){
                s.pop();
            }
            if(s.empty())
                ans.push_back(-1);
            else
                ans.push_back(s.top());
        }
        s.push(arr[i]);
    }
    return ans;
}
int main(){
    vector<int>arr={3,4,6,2,5,0};

    vector<int> ans=nearestSmallerL(arr);

    for(int i:ans){
        cout<<i<<" ";
    }
     
    return 0;
}