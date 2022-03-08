#include<bits/stdc++.h>
using namespace std;

void findCombination(vector<int>&arr,int target,int index, vector<vector<int>>&ans, vector<int>subset) {    

    if (index == arr.size()) {
        if (target == 0) {
          ans.push_back(subset);
        }
        return;
      }
      

    if (arr[index] <= target) {
        subset.push_back(arr[index]);
        findCombination(arr,target-arr[index],index+1,ans,subset);
        subset.pop_back();
    }

    findCombination(arr,target,index+1,ans,subset);
    
}

// Better Approach
void findCombination2(vector<int>&arr,int target,int index, vector<vector<int>>&ans, vector<int>subset) {    

    if (target == 0) {
        ans.push_back(subset);
    }

    for (int i = index; i < arr.size(); i++) {
        if (i != index && arr[i] == arr[i - 1]) continue;
        if (arr[i] <= target) {
            subset.push_back(arr[i]);
            findCombination2(arr,target-arr[i],i+1,ans,subset);
            subset.pop_back();
        }
    }

}


int main(){

    vector<int> arr={10,1,2,7,6,1,5};
    vector<int>subset;
    vector<vector<int>>ans;
    sort(arr.begin(),arr.end());
    findCombination2(arr,8,0,ans,subset);

    for(vector<int>i:ans){
        for(int j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}