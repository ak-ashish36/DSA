//https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
//https://www.codingninjas.com/codestudio/problems/minimum-insertions-to-make-palindrome_985293
//https://youtu.be/xPBLEj41rFU

//For minimum number of Deletion to make string palindrome , Apply the same logic nothing changes
#include<bits/stdc++.h>
using namespace std;
class Solution {
    int lcs(int n1, int n2,string s1,string s2,vector<vector<int>>&dp){
        if(n1<0||n2<0){
            return 0;
        }
        if(dp[n1][n2]!=-1){return dp[n1][n2];}
        if(s1[n1]==s2[n2]){
            return dp[n1][n2]=1+lcs(n1-1,n2-1,s1,s2,dp);
        }else{
            return dp[n1][n2]=max(lcs(n1-1,n2,s1,s2,dp),lcs(n1,n2-1,s1,s2,dp));
        }
    }
public:
    int minInsertions(string s) {
        string s2=string(s.rbegin(), s.rend());
        int n= s.length();
        vector<vector<int>>dp(n,vector<int>(n,-1));

        int longestPalindromicSubSequence= lcs(n-1,n-1,s,s2,dp);

        return n-longestPalindromicSubSequence;
    }

    int minInsertions2(string s) {
        string s2=string(s.rbegin(), s.rend());
        int n= s.length();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        

        for(int i=0;i<=n;i++){         //Index right shifting is done to handle the base case 
            for(int j=0;j<=n;j++){
                if(i==0 || j==0){
                    dp[i][j]=0;
                }else{
                    if(s[i-1]==s2[j-1]){
                        dp[i][j] = 1 +dp[i-1][j-1];
                    }else{
                        dp[i][j] = 0 + max(dp[i-1][j] , dp[i][j-1]);
                    }
                }
            }
        }
        int longestPalindromicSubSequence= dp[n][n];
        return n-longestPalindromicSubSequence;
    }

};
int main(){
    string s="mbadm";
    //Output : 2
    Solution obj;
    cout<<obj.minInsertions2(s);
    return 0;
}