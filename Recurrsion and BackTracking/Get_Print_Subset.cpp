#include<bits/stdc++.h>
using namespace std;

void printSubset(vector<int>arr, set<vector<int>>&ans, int index, vector<int>subset){

    if(index==arr.size()){
        sort(subset.begin(), subset.end());
        ans.insert(subset);
        return;
    }

    subset.push_back(arr[index]);
    printSubset(arr,ans,index+1,subset);
    subset.pop_back();
    printSubset(arr,ans,index+1,subset);
}
// Better approach but it needs sorted array
void findSubsets(vector<int>&arr, vector<vector<int>>&ans, int index, vector<int>subset) {
    ans.push_back(subset);

    for (int i = index; i < arr.size(); i++) {
        if (i != index && arr[i] == arr[i - 1]) continue;

        subset.push_back(arr[i]);
        findSubsets(arr,ans,i+1,subset);
        subset.pop_back();
    }
}


void solution1(vector<int>arr){
    vector<int>subset;
    set<vector<int>>ans;

    printSubset(arr,ans,0,subset);

    for(vector<int>i:ans){
        for(int j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

}
void solution2(vector<int>&arr){
    sort(arr.begin(),arr.end());
    vector<int>subset;
    vector<vector<int>>ans;

    findSubsets(arr,ans,0,subset);

    for(vector<int>i:ans){
        for(int j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
int main(){
    vector<int>arr={1,2,2};
    solution1(arr);
    // solution2(arr);
    return 0;
}