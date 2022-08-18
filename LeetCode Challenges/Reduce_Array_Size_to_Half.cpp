//https://leetcode.com/problems/reduce-array-size-to-the-half/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n=arr.size();    //n=10
        map<int,int>mpp;
        for(int i:arr){     //{3:4 , 5:3 , 2:2 ,7:1}
            mpp[i]++;
        }

        priority_queue<int> maxH;  //{4,3,2,1}
        for(auto it :mpp){
            maxH.push(it.second);
        }
  
        int count=0;
        int elem =0;
        while(!maxH.empty()){
            count+=maxH.top();
            maxH.pop();
            elem++;
            if(count>=n/2){
                return elem;
            }
        }
        return elem;
    }
};
int main(){
    vector<int>arr={9,77,63,22,92,9,14,54,8,38,18,19,38,68,58,19};
    Solution obj;
    cout<<obj.minSetSize(arr);
    return 0;
}