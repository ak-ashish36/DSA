//https://leetcode.com/problems/find-k-closest-elements/submissions/
//https://www.codingninjas.com/codestudio/problems/find-k-closest-elements_1263702/
//https://practice.geeksforgeeks.org/problems/k-closest-elements3619/1
//https://youtu.be/J8yLD-x7fBI
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        priority_queue<pair<int,int>> maxH;

        for(int i=0;i<arr.size();i++){
            maxH.push({abs(arr[i]-x),arr[i]});
            if(maxH.size()>k){
                maxH.pop();
            }
        }

        vector<int>ans;
        while(!maxH.empty()){
           ans.push_back(maxH.top().second);
           maxH.pop();
        }   
        sort(ans.begin(),ans.end());
        return ans;
    }
};
int main(){
    vector<int>arr={1,2,3,4,5};
    int k=4,x=3;
    //Output ={1,2,3,4}
    Solution obj;
    vector<int>ans=obj.findClosestElements(arr,k,x);
    for(int i:ans){
        cout<<i<<" ";
    }
    return 0;
}