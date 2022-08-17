//https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1
//https://www.codingninjas.com/codestudio/problems/longest-common-substring_1235207/
//https://youtu.be/_wP9mWNPL5w
#include<bits/stdc++.h>
using namespace std;
class Solution {
    int solve(int n1,int n2,string s1, string s2,vector<vector<int>>&dp,int &count){
        if(n1<0 || n2<0){
            return 0;
        }
        if(dp[n1][n2]!=-1){return dp[n1][n2];}

        int take=0;
        if(s1[n1]==s2[n2]){
            take=1+solve(n1-1,n2-1,s1,s2,dp,count);
        }
        int a=solve(n1-1,n2,s1,s2,dp,count);
        int b=solve(n1,n2-1,s1,s2,dp,count);

        count=max(count,take);
    
        return dp[n1][n2]=take;
    }
public:
//Recursion T=O(2^n * 2^m) S=O(N+M) , Memoization T=O(N*M)  S=O(N*M) +O(N+M)
    int longestCommonSubString(string text1, string text2) {
        int n1=text1.length(),n2=text2.length();
        vector<vector<int>>dp(n1,vector<int>(n2,-1));
        int count=0;
        solve(n1-1,n2-1,text1,text2,dp,count); 
        return count;
    }

// Tabulation  T=O(N*M)  S=O(N*M)
    int longestCommonSubString2(string text1, string text2) {
        int n1=text1.length(),n2=text2.length();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
        int ans=0;
        for(int i=0;i<=n1;i++){         //Index right shifting is done to handle the base case 
            for(int j=0;j<=n2;j++){

                if(i==0 || j==0){
                    dp[i][j]=0;
                }else{
                    if(text1[i-1]==text2[j-1]){
                        dp[i][j] = 1 +dp[i-1][j-1];
                    }else{
                        dp[i][j] = 0 ;
                    }
                }
                ans=max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};
int main(){
    string s1="abcjklp",s2="acjkp";
    //Output : 3
    Solution obj;
    cout<<obj.longestCommonSubString(s1,s2);
    return 0;
}