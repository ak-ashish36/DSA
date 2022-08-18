//https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1
//https://www.codingninjas.com/codestudio/problems/connect-ropes_975278/
//https://youtu.be/_k_c9nqzKN0
#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    int minCost(vector<int>arr){
        int n=arr.size();
        priority_queue <int, vector<int>, greater<int> > minH;

        for(int i=0;i<n;i++){
            minH.push(arr[i]);
        }
        
        int cost=0;
        while(minH.size()>=2){
            int x=minH.top();
            minH.pop();
            int y=minH.top();
            minH.pop();
            cost+=x+y;
            minH.push(x+y);
        }
        return cost;
    }
};
int main(){
    
    return 0;
}