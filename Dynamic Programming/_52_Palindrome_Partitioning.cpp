//https://leetcode.com/problems/palindrome-partitioning-ii/
//https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1
//https://www.codingninjas.com/codestudio/problems/palindrome-partitioning_873266/
//https://youtu.be/_H8V5hJUGd0
#include <bits/stdc++.h>
using namespace std;
class Solution {
    bool isPalindrome(string &s){
        int i=0,j=s.length()-1;
        while(i<j){
            if(s[i++]!=s[j--]){return false;}
        }
        return true;
    }
    int solve(int i,int n,string s,vector<int>&dp){
        if(i==n){return 0;}
        if(dp[i]!=-1){return dp[i];}

        string temp="";
        int minCost=1e9;
        for(int j=i;j<n;j++){
            temp+=s[j];
            if(isPalindrome(temp)){
                int cost = 1+solve(j+1,n,s,dp);
                minCost=min(minCost,cost);
            }
        }
        return dp[i]=minCost;
    }
public:
//Memoization
    int minCut(string s) {
        int n=s.length();
        vector<int>dp(n,-1);
        return solve(0,n,s,dp)-1;
    }
//Tabulation
    int minCut2(string s) {
        int n=s.length();
        vector<int>dp(n+1,0);
        dp[n]=0;
        for(int i=n-1;i>=0;i--){
            string temp="";
            int minCost=1e9;
            for(int j=i;j<n;j++){
                temp+=s[j];
                if(isPalindrome(temp)){
                    int cost = 1+dp[j+1];
                    minCost=min(minCost,cost);
                }
            }
            dp[i]=minCost;
        }
        return dp[0]-1;
    }
};
int main(){
    string str="aab";
    // Output = 1 cut => aa|b
    Solution obj;
    cout<<obj.minCut2(str);
    return 0;
}