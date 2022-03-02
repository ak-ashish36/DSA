//https://leetcode.com/problems/merge-intervals/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
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
        print(mergedIntervals);
        return mergedIntervals;
    }
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
};
int main(){
    vector<vector<int>> intervals;
    intervals={{1,3},{2,6},{8,10},{9,11},{15,18},{2,4},{16,17}};
    Solution obj;
    cout<<"Before Merging"<<endl;
    obj.print(intervals);
    cout<<"After Merging"<<endl;
    obj.merge(intervals);
   return 0;
}