//https://leetcode.com/problems/fruit-into-baskets/
//https://youtu.be/seOKHXB_w74
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int totalToys(vector<int>& fruits) {
        int n=fruits.size();
        int i=0,j=0;
        int length=-1;
        if(n<=2){return n;}
        unordered_map<int,int> m;
        while(j<n){
           m[fruits[j]]++;
           if(m.size() <= 2){
               length=max(length,j-i+1);
           }
           else if(m.size() > 2){
               while(m.size() > 2){
                   m[fruits[i]]--;
                   if(m[fruits[i]] == 0) m.erase(fruits[i]);
                   i++;
               }
           }
           j++;
        }
        return length;
    }
};
int main(){
    vector<int>fruits={1,2,3,2,2};
    //Output = 4 {2,3,2,2}
    Solution obj;
    cout<<obj.totalToys(fruits);
    return 0;
}