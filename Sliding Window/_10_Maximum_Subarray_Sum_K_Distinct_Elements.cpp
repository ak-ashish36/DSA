//https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1
//https://youtu.be/Lav6St0W_pQ
#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    int maximumDistinctSubarraySum(vector<int>&arr, int k) {
        int n=arr.size();
        int i=0,j=0;
        int sum=0;
        int maxi=-1e9;
        set<int>set;
        while(j<n){
            while(set.count(arr[j]) || set.size() >= k){
                sum-=arr[i];
                set.erase(arr[i]);
                i++;
            }
            sum+=arr[j]; 
            set.insert(arr[j]);
            if(set.size()==k){
                maxi=max(maxi,sum);
            }
            j++;
        }
        return maxi;
    }
};
int main(){
    vector<int>arr={1,2,1,2,3};
    int k=2;
    //Output = 9  {4,3,2}
    Solution obj;
    cout<<obj.maximumDistinctSubarraySum(arr,k);
    return 0;
}