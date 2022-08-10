//https://www.codingninjas.com/codestudio/problems/move-all-negative-numbers-to-beginning-and-positive-to-end_1112620
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
//T: O(n) S: O(1)
    void moveNegatives(vector<int>& arr) {
        int j=arr.size()-1;
        for(int i=arr.size()-1;i>=0;i--){
            if(arr[i]>=0){
                swap(arr[i],arr[j]);
                j--;
            }
        }
    }

//T: O(n) S: O(1)
    void moveNegatives2(vector<int>&arr){
        int j = 0;
        for (int i=0;i<arr.size();i++) {
            if(arr[i] < 0){
                swap(arr[i], arr[j]);
                j++;
            }
        }
    }
};
int main(){
    vector<int>arr={1,-4,-2,5,3};
    Solution obj;
    obj.moveNegatives(arr);
    for(int i :arr){cout<<i<<" ";}
    cout<<endl;
    arr={1,-4,-2,5,3};
    obj.moveNegatives2(arr);
    for(int i :arr){cout<<i<<" ";}
    return 0;
}