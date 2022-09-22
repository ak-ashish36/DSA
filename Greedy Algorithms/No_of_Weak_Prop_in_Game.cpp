//https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/
#include <bits/stdc++.h>
using namespace std;
class Solution {
    static bool comp(vector<int> &a,vector<int> &b){
        if(a[0]!=b[0])
            return a[0]>b[0];
        return a[1]<b[1];
    }
public:
    int numberOfWeakCharacters(vector<vector<int>>& prop) {
        //Sort attack in desc order and defense in ascending if attack is equal
        sort(prop.begin(),prop.end(),comp);
        int currDefense =prop[0][1];
        int ans=0;
        for(auto it:prop){
            //Attack is already greater
            if(currDefense>it[1]){
                ans++;
            }else{
                currDefense=it[1];
            }
        }
        return ans;
    }
};
int main(){
    vector<vector<int>>properties={{7,7},{7,6},{6,6}};
    Solution obj;
    cout<<obj.numberOfWeakCharacters(properties);
    
    return 0;
}