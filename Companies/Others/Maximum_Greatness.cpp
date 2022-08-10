#include <bits/stdc++.h>
using namespace std;
int findMaximumGreatness(vector<int>arr){
    int n=arr.size();
    map<int,int>mpp;
    for(int i :arr){
        mpp[i]++;
    }

    int max_greatness=0;
    for(int i=0;i<n;i++){
        for(auto it :mpp){
            if(it.first>arr[i] && it.second>0){
                max_greatness++;
                mpp[it.first]--;
                break;
            }
        }
    }

    return max_greatness;
}
int main(){
    vector<int>arr={1,3,5,2,1,3,1};
    // map =[{1-3},{2-1},{3-2},{5-1}]
    cout<<findMaximumGreatness(arr);
    return 0;
}