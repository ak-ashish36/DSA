//https://youtu.be/tyB0ztf0DNY
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    // Recursion
    int fibb(int n){
        if(n<=1){
            return n;
        }
        else{
            return fibb(n-1)+fibb(n-2);
        }
    }
    // Recursion + Memoization   T=O(n)   S=O(n)+O(n) (Stack space + dp arr)
    int fibb2(int n,vector<int>&dp){
        if(n<=1){
            return n;
        }
        if(dp[n]!=-1){return dp[n];}
        else{

            return dp[n]=fibb(n-1)+fibb(n-2);
        }
    }
    //Tabulation T=O(n)   S=O(n)
    int fibb3(int n){
        vector<int>dp(n+1,-1);
        //Base Cases
        dp[0]=0;dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};
int main(){
    int n=7;
    Solution obj;
    cout<<"Norma fibbsion : "<<obj.fibb(n)<<endl; 
    vector<int>dp(n+1,-1);
    cout<<"Memoization : "<<obj.fibb2(n,dp)<<endl;
    cout<<"Tabulization : "<<obj.fibb3(n)<<endl;
    return 0;
}