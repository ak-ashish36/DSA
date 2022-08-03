//https://leetcode.com/problems/distinct-subsequences
//https://www.codingninjas.com/codestudio/problems/subsequence-counting_3755256
//https://youtu.be/nVG7eTiD2bY
#include<bits/stdc++.h>
using namespace std;
class Solution {
    int solve(int i,int j,string s, string t,vector<vector<int>>&dp){
        //Base Cases
        //If string t is exhausted it means one distinct value is found in string s
        if(j<0){return 1;}
        //If string s is exhausted and t is not than it means no distinct value is found 
        if(i<0){return 0;}

        if(dp[i][j]!=-1){return dp[i][j];}

        if(s[i]==t[j]){
            //If last char of both strings are same than we have two option either to take last char of t or not
            return dp[i][j]=(solve(i-1,j-1,s,t,dp) + solve(i-1,j,s,t,dp));
        }else{
            //If last char of both strings are not same than look for another char in string s
            return dp[i][j]=solve(i-1,j,s,t,dp);
        }
    }
public:
//Memoization
    int numDistinct(string s, string t) {
        int n1=s.length();
        int n2 =t.length();
        vector<vector<int>>dp(n1,vector<int>(n2,-1));
        return solve(n1-1,n2-1,s,t,dp);
    }
//Tabulation
    int numDistinct2(string s, string t) {
        int n1=s.length();
        int n2 =t.length();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));

        for(int i=0;i<=n1;i++){
            dp[i][0]=1;
        }
        for(int j=1;j<=n2;j++){
            dp[0][j]=0;
        }

        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n1][n2];
    }

};
int main(){
    string s= "babgbag";
    string t= "bag";
    //Output : 5
    Solution obj;
    cout<<obj.numDistinct2(s,t);
    return 0;
}