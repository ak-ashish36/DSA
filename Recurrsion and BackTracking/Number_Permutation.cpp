#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    //function to generate all possible permutations of a string
    void solve(vector<int>&arr,vector<int>&path, vector<vector<int>> & res) {
      if (arr.size()==0) {
        res.push_back(path);
        return;
      }
      for (int i =0; i < arr.size(); i++) {
        int c=arr[i];
        vector<int>rem_arr=arr;
        rem_arr.erase(rem_arr.begin() + i);
        path.push_back(c);
        solve(rem_arr,path,res);
        path.pop_back();
      }
    }

  vector<vector<int>> permute(vector<int>& nums) {
    
    vector<vector<int>>ans;
    vector<int>path;

    solve(nums,path,ans);
   
    return ans;
        
    }
};
int main() {
  vector<int>arr={1,2,3};
  Solution obj;
   vector<vector<int>>ans = obj.permute(arr);

   for(vector<int> i:ans){
       for(int j:i){
           cout<<j<<" ";
       }
       cout<<endl;
   }

  return 0;
}