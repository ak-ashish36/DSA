//https://leetcode.com/problems/k-closest-points-to-origin/
//https://www.codingninjas.com/codestudio/problems/k-closest-points-to-origin_1094908/
//https://youtu.be/XC4EotTewro
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue< pair<int,vector<int>> >maxH;
        
        for(int i=0;i<points.size();i++){
            vector<int>p1=points[i];
            int distance = p1[0]*p1[0]  +p1[1]*p1[1];

            maxH.push({distance,p1});
            if(maxH.size()>k){
                maxH.pop();
            }
        }
        vector<vector<int>>ans;
        while(!maxH.empty()){
            ans.push_back(maxH.top().second);
            maxH.pop();
        }

        return ans;
    }
};
int main(){
    vector<vector<int>>points={{1,3},{-2,2}};
    int k=1;
    //Output = {-2,2}
    Solution obj;
    points=obj.kClosest(points,k);
    for(auto i :points){
        for(int j :i){cout<<j<<" ";}
        cout<<endl;
    }
    return 0;
}