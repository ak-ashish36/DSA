//https://leetcode.com/problems/longest-common-subsequence
//https://www.codingninjas.com/codestudio/problems/longest-common-subsequence_624879
//https://youtu.be/NPZn9jBrX8U
#include<bits/stdc++.h>
using namespace std;
class Solution {
    int solve(int n1,int n2,string s1, string s2,vector<vector<int>>&dp){
        if(n1<0 || n2<0){
            return 0;
        }
        if(dp[n1][n2]!=-1){return dp[n1][n2];}

        if(s1[n1]==s2[n2]){
            return dp[n1][n2] = 1 +solve(n1-1,n2-1,s1,s2,dp);
        }else{
            return dp[n1][n2] = 0 + max(solve(n1-1,n2,s1,s2,dp),solve(n1,n2-1,s1,s2,dp));
        }
    }
public:
//Recursion T=O(2^n * 2^m) S=O(N+M) , Memoization T=O(N*M)  S=O(N*M) +O(N+M)
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.length(),n2=text2.length();
        vector<vector<int>>dp(n1,vector<int>(n2,-1));
        return solve(n1-1,n2-1,text1,text2,dp);
    }
// Tabulation  T=O(N*M)  S=O(N*M)
    int longestCommonSubsequence2(string text1, string text2) {
        int n1=text1.length(),n2=text2.length();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));

        for(int i=0;i<=n1;i++){         //Index right shifting is done to handle the base case 
            for(int j=0;j<=n2;j++){
                if(i==0 || j==0){
                    dp[i][j]=0;
                }else{
                    if(text1[i-1]==text2[j-1]){
                        dp[i][j] = 1 +dp[i-1][j-1];
                    }else{
                        dp[i][j] = 0 + max(dp[i-1][j] , dp[i][j-1]);
                    }
                }
            }
        }
        return dp[n1][n2];
    }
// Tabulation Space Optimization  T=O(N*M)  S=O(M)
    int longestCommonSubsequence3(string text1, string text2) {
        int n1=text1.length(),n2=text2.length();
        vector<int>prev(n2+1,0);
        vector<int>curr(n2+1,0);

        for(int i=0;i<=n1;i++){         //Index right shifting is done to handle the base case 
            for(int j=0;j<=n2;j++){
                if(i==0 || j==0){
                    curr[j]=0;
                }else{
                    if(text1[i-1]==text2[j-1]){
                        curr[j] = 1 +prev[j-1];
                    }else{
                        curr[j] = 0 + max(prev[j] , curr[j-1]);
                    }
                }
            }
            prev=curr;
        }
        return prev[n2];
    }

};
int main(){
    string s1="abcde",s2="ace" ;
    //Output : 3
    Solution obj;
    cout<<obj.longestCommonSubsequence3(s1,s2);
    return 0;
}