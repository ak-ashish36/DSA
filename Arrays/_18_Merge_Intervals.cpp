//https://leetcode.com/problems/merge-intervals/
//https://practice.geeksforgeeks.org/problems/8a644e94faaa94968d8665ba9e0a80d1ae3e0a2d/1
//https://www.codingninjas.com/codestudio/problems/699917
//https://youtu.be/2JzRBPFYbKE
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>&intervals) {
        vector<vector<int>> mergedIntervals;
        if(intervals.size() == 0){
            return mergedIntervals;
        }
        sort(intervals.begin(), intervals.end());
        vector<int> temp = intervals[0];
        
        for(auto x: intervals){
            if(x[0] <= temp[1]){
                temp[1] = max(temp[1], x[1]);
            }
            else{
                mergedIntervals.push_back(temp);
                temp = x;
            }
        }
        mergedIntervals.push_back(temp);
        return mergedIntervals;
    }
};
void print(vector<vector<int>>& arr){
    for(auto r: arr){
        cout<<"{";
        for(auto c :r){
            cout<<c<<",";
        }
        cout<<"}";
        cout<<",";
    }
    cout<<endl;
}
int main(){
    vector<vector<int>>intervals={{1,3},{2,6},{8,10},{9,11},{15,18},{2,4},{16,17}};
    //Output = {1,6,},{8,11,},{15,18}
    Solution obj;
    intervals=obj.merge(intervals);
    print(intervals);
   return 0;
}