#include<bits/stdc++.h>
using namespace std;
vector<int> nearestGreaterL(vector<int>arr){
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
    return ans; 
}
vector<int> nearestGreaterR(vector<int>arr){
    int size=arr.size();
    vector<int>ans;
    stack<pair<int,int>>s;
    for(int i=arr.size()-1;i>=0;i--){
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
    reverse(ans.begin(),ans.end());
    return ans;
}
int maxSpecialProduct(vector<int> &A) {
    vector<int>leftSpecial=nearestGreaterL(A);
    vector<int>rightSpecial=nearestGreaterR(A);

    for(int i :leftSpecial){
        cout<<i<<" ";
    }
    cout<<endl;
    for(int i :rightSpecial){
        cout<<i<<" ";
    }
    cout<<endl;

    int maxi=INT_MIN;
    for(int i=0;i<A.size();i++){
        if(leftSpecial[i]==-1 && rightSpecial[i]==-1){}
        else{maxi=max(maxi,leftSpecial[i]*rightSpecial[i]);}
    }
    return maxi;
}
int main(){
    vector<int>arr={1,4,3,4};
    cout<<maxSpecialProduct(arr);
     
    return 0;
}