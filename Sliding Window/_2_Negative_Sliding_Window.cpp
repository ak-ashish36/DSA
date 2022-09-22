//https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1
//https://youtu.be/uUXXEgK2Jh8
#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    //Brute Force T=O(nk)  S=O(1)
    vector<int>firstNegInteger(vector<int>&arr,int k){
        int n=arr.size();
        vector<int>ans;
    
        for(int i=0;i<=n-k;i++){
            bool found=false;
            for(int j=i;j<=i+k-1;j++){
                if(arr[j]<0){
                    found=true;
                    ans.push_back(arr[j]);
                    break;
                }
            }
            if(!found){
                ans.push_back(0);
            }
        }
        return ans;
    }
//Optimised T=O(n) S=O(n)
    vector<int>firstNegInteger2(vector<int>&arr,int k){
        int n=arr.size();
        vector<int>ans;

        queue<int>q;
        int i=0,j=0;
        for(j=0;j<n;j++){
            if(arr[j]<0){
                q.push(arr[j]);
            }
            if(j-i+1 == k){
                if(q.empty()){ans.push_back(0);}
                else{ans.push_back(q.front());
                    if(q.front()==arr[i]){
                        q.pop();
                    }
                }
                i++;
            }
        }

        return ans;
    }

};
int main(){
    vector<int>arr={8, 2, 3, 6, 10};
    int k=2;
    //Output = {-8,0,-6,-6};
    Solution obj;
    for(int i:obj.firstNegInteger2(arr,k)){cout<<i<<" ";}
    return 0;
}