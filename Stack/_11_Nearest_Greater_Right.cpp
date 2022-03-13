#include<bits/stdc++.h>
using namespace std;
vector<int> nearestGreater(vector<int>arr){
    vector<int>ans;
    stack<int>s;
    for(int i=arr.size()-1;i>=0;i--){
        if(s.empty()){
            ans.push_back(-1);
        }
        else if(s.top()>arr[i]){
            ans.push_back(s.top());
        }

        else if(s.top()<=arr[i]){
            while(!s.empty() && s.top()<=arr[i]){
                s.pop();
            }
            if(s.empty())
                ans.push_back(-1);
            else
                ans.push_back(s.top());
        }
        s.push(arr[i]);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main(){
    vector<int>arr={2,9,5,6,7};

    vector<int> ans=nearestGreater(arr);

    for(int i:ans){
        cout<<i<<" ";
    }
     
    return 0;
}