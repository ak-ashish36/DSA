//https://practice.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1
#include<bits/stdc++.h>
using namespace std;
// Time complexity: O(nk2).
class Solution{
    public:
    vector<int> countDistinct(vector<int>&arr,int k){
        int n=arr.size();
        vector<int>ans;
        for(int i=0;i<n-k+1;i++){
            int dist_count = 0;
            for(int j=i;j<i+k;j++){
                int l;
                for(l=i;l<j;l++){
                    if(arr[j]==arr[l]) break;
                }
                if(j==l){
                    dist_count++;
                }
            }
            ans.push_back(dist_count);
        }
        return ans;
    }
//Time complexity O(n)
    vector<int> countDistinct2(vector<int>&arr,int k){
        int n=arr.size();
        int i=0,j=0;
        unordered_map<int,int>map;
        vector<int>ans;
        while(j<n){
            map[arr[j]]++;
            if(j-i+1==k){
                ans.push_back(map.size());
                map[arr[i]]--;
                if(map[arr[i]]==0){map.erase(arr[i]);}
                i++;
            }
            j++;
        }
        return ans;
    }
};

int main(){
    vector<int>arr={1,2,1,3,4,2,3};
    int k=4;
    //Output = {3,4,4,3}
    Solution obj;
    for(int i:obj.countDistinct2(arr,k)){
        cout<<i<<" ";
    }
    return 0;
}