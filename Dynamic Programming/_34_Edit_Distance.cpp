//https://leetcode.com/problems/edit-distance
//https://www.codingninjas.com/codestudio/problems/edit-distance_630420
//https://youtu.be/fJaKO8FbDdo
#include<bits/stdc++.h>
using namespace std;
class Solution {
    int solve(int i, int j, string s1, string s2, vector<vector<int>>&dp){
        //Base Cases
        //If s1=" " and s2="ros" than we need to add all char of s2 to s1 (j+1) bcoz of 0 bases indexing
        if(i<0){
            return j+1;    
        }
        //If s1="hor" and s2="" than we need to delete all char from s1 (i+1) bcoz of 0 bases indexing
        if(j<0){
            return i+1;
        }

        if(dp[i][j]!=-1){return dp[i][j];}

        if(s1[i]==s2[j]){
            return dp[i][j]=solve(i-1,j-1,s1,s2,dp);
        }
        else{
            int insertion = 1+ solve(i,j-1,s1,s2,dp);
            int deletion = 1+ solve(i-1,j,s1,s2,dp);
            int replace = 1+ solve(i-1,j-1,s1,s2,dp);

            return dp[i][j]=min(insertion, min(deletion,replace));
        }
    }
public:
//Memoization
    int minDistance(string word1, string word2) {
        int n1=word1.length();
        int n2=word2.length();
        vector<vector<int>>dp(n1,vector<int>(n2,-1));
        return solve(n1-1,n2-1,word1,word2,dp);
    }
//Tabulation
    int minDistance2(string word1, string word2) {
        int n1=word1.length();
        int n2=word2.length();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));

        for(int i=0;i<=n1;i++){
            dp[i][0]=i; 
        }
        for(int j=0;j<=n2;j++){
            dp[0][j]=j;
        }

        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }else{
                    int insertion = 1+dp[i][j-1];
                    int deletion = 1+dp[i-1][j];
                    int replace = 1+dp[i-1][j-1];

                    dp[i][j]=min(insertion, min(deletion,replace));
                }
            }
        }
        return dp[n1][n2];
    }

};
int main(){
    string s1="horse";
    string s2="ros";
    //Output : 3
    Solution obj;
    cout<<obj.minDistance2(s1,s2)<<endl; 
    return 0;
}