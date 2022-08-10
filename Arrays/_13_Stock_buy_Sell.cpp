//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
//https://www.codingninjas.com/codestudio/problems/893405/
//https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stocks-i/
//https://youtu.be/eMSfBgbiEjk
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
//Time  = O(n2)   S=O(1)
    int maxProfit(vector<int>& arr){
        int max_profit=0;
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                if(arr[j]-arr[i]>max_profit){
                max_profit=arr[j]-arr[i];
                }
            }
        }
        return max_profit;   
    }
//Time  = O(n)   S=O(1)
    int maxProfit2(vector<int>& prices) {
        int minimal =prices[0];
        int profit=0;
        for(int i=1;i<prices.size();i++){
            profit=max(profit,prices[i]-minimal);
            minimal =min(minimal ,prices[i]);
        }
        return profit;
    }
};
int main(){
    vector<int> prices={7,1,5,3,6,4};
    //Output = 5
    Solution obj;
    int profit=obj.maxProfit2(prices);
    cout<<profit;
   return 0;
}