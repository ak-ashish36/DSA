//https://practice.geeksforgeeks.org/problems/nearly-sorted-1587115620/1
//https://www.codingninjas.com/codestudio/problems/nearly-sorted_982937/
//https://youtu.be/dYfM6J1y0mU
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    vector<int>nearlySorted(vector<int>arr,int k){
        int n=arr.size();
        priority_queue <int, vector<int>, greater<int> > minH;

        vector<int>ans;
        for(int i=0;i<n;i++){
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
};
int main(){
    vector<int>arr={6,5,3,2,8,10,9};
    int k=4;
    Solution obj;
    vector<int>ans=obj.nearlySorted(arr,k);
    for(int i:ans){
        cout<<i<<" ";
    }

    return 0;
}