//https://leetcode.com/problems/delete-operation-for-two-strings
//https://www.codingninjas.com/codestudio/problems/can-you-make_4244510
//https://youtu.be/yMnH0jrir0Q
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
    int minDistance(string word1, string word2){
        int n1=word1.length();
        int n2=word2.length();
        vector<vector<int>>dp(n1,vector<int>(n2,-1));

        int longestCommonSubSeq=lcs(n1-1,n2-1,word1,word2,dp);

        int deletion = n1-longestCommonSubSeq;
        int insertion =n2-longestCommonSubSeq;

        return deletion+insertion; 
    }
};
int main(){
    string word1="sea",word2="eat";
    //Output : 2
    Solution obj;
    cout<<obj.minDistance(word1,word2); 
    return 0;
}