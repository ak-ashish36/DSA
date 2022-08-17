//https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1
//https://www.codingninjas.com/codestudio/problems/problem-name-boolean-evaluation_1214650/
//https://youtu.be/MM7fXopgyjw
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int mod =1003;
class Solution {
    ll solve(int i,int j, bool isTrue, string str,vector<vector<vector<ll>>>&dp){
        if(i>j){return 0;}
        if(i==j){
            if(isTrue){return str[i]=='T';}
            else{return str[i]=='F';}
        }
        if(dp[i][j][isTrue]!=-1){return dp[i][j][isTrue];}
        ll ways=0;
        for(int k=i+1; k<=j-1; k+=2){
            ll LT = solve(i,k-1,1,str,dp);
            ll LF = solve(i,k-1,0,str,dp);
            ll RT = solve(k+1,j,1,str,dp);
            ll RF = solve(k+1,j,0,str,dp);

            if(str[k]=='&'){
                if(isTrue){
                    ways += (LT*RT)%mod ;
                }else{
                    ways += ((LT*RF)%mod + (LF*RT)%mod + (LF*RF)%mod)%mod ;
                }
            }
            else if(str[k]=='|'){
                if(isTrue){
                   ways += ( (LT*RT)%mod + (LT*RF)%mod + (RT*LF)%mod)%mod;
                }else{
                    ways += (LF*RF)%mod;
                }
            }
            else if(str[k]=='^'){
                if(isTrue){
                    ways += ((LT*RF)%mod + (LF*RT)%mod)%mod;
                }else{
                    ways += ((LT*RT)%mod + (LF*RF)%mod)%mod;
                }
            }
        }
        return dp[i][j][isTrue]=(ways)%mod;
    }
public:
    int countWays(string expression) {
        int n=expression.length();
        vector<vector<vector<ll>>>dp(n,vector<vector<ll>>(n,vector<ll>(2,-1)));
        return solve(0,n-1,1,expression,dp);
    }
};
int main(){
    string s ="T|T&F^T";
    //Output =4
    Solution obj;
    cout<<obj.countWays(s);
    return 0;
}