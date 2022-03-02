//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
#include<bits/stdc++.h>
using namespace std;
int maxProfit(vector<int>& arr) {
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
//better approach
int maxProfit2(vector<int> &arr){
    int minimal =INT_MAX;
    int profit=0;
 
    for(int i=0;i<arr.size();i++){
        if(arr[i]<minimal){
            minimal=arr[i];
        }
        if(arr[i]-minimal>profit){
            profit=arr[i]-minimal;
        }
    }
    
    return profit;
}
int main(){
    vector<int> prices;
    prices={7,1,5,3,6,4};
    int profit=maxProfit2(prices);
    cout<<profit;
   return 0;
}