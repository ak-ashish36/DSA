#include<bits/stdc++.h>
using namespace std;
int sol(string str){
    unordered_map<char,int>mpp;
    for(int i=0;i<str.length();i++){
        mpp[str[i]]++;
    }
    int maxi=0;
    int ans;
    
    for(auto it :mpp){
        if(it.second>=maxi){
            maxi=it.second;
            ans=it.first-'0';
        }
    }
    
    vector<int>num;
    for(auto it:mpp){
        if(it.second==maxi){
            num.push_back(it.first-'0');
        }
    }
    sort(num.begin(),num.end());
    return num[0];
}
int main(){
    string s="33333222220000011111"; 
    cout<<sol(s);
    return 0;
}