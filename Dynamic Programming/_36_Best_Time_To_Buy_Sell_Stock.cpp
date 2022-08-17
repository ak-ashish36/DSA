//Dp on Stocks
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock
//https://www.codingninjas.com/codestudio/problems/stocks-are-profitable_893405/
//https://youtu.be/excAOvwF_Wk
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
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
    vector<int>prices={7,1,5,3,6,4};
    //Output : 5
    Solution obj;
    cout<<obj.maxProfit(prices);
    return 0;
}