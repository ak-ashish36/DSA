//https://leetcode.com/problems/wildcard-matching/
//https://practice.geeksforgeeks.org/problems/wildcard-pattern-matching/1
//https://www.codingninjas.com/codestudio/problems/wildcard-pattern-matching_701650/
//https://youtu.be/ZmlQ3vgAOMo
#include<bits/stdc++.h>
using namespace std;
class Solution {
    bool solve(int i, int j ,string pattern, string text,vector<vector<int>>&dp){
        //Base Cases
        //Both string is exhausted it means we find the pattern
        if(i<0 && j<0){return true;}

        //if pattern is exhausted and text is remaining , than matching not possible
        else if(i<0 && j>=0){return false;}
        
        //if pattern is available and text is exhausted we need to check for '*' in pattern bcoz '*' also means null
        else if(i>=0 && j<0 ){
            for(int x=0;x<=i;x++){
                if(pattern[x]!='*'){return false;}
            }
            return true;
        }

        if(dp[i][j]!=-1){return dp[i][j];}

        if(pattern[i]==text[j] || pattern[i]=='?'){
            return dp[i][j]=solve(i-1,j-1,pattern,text,dp);
        }
        else if(pattern[i]=='*'){
            //Consider * as null and move forward
            bool left = solve(i-1,j,pattern,text,dp);
            //consider 1 char from text and move forward
            bool right = solve(i,j-1,pattern,text,dp);

            return dp[i][j]=left||right;
        }
        return dp[i][j]=false;
    }
public:
//Memoization
    bool isMatch(string text, string pattern) {
        int n1=pattern.length();
        int n2= text.length();
        vector<vector<int>>dp(n1,vector<int>(n2,-1));
        return solve(n1-1,n2-1,pattern,text,dp);
    }
//Tabulation
    bool isMatch2(string text, string pattern) {
        int n1=pattern.length();
        int n2= text.length();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
        
        //Base Cases
        dp[0][0]=true;
        for(int j=1;j<=n2;j++){dp[0][j]=false;}
        for(int i=1;i<=n1;i++){
            dp[i][0]=true;
            for(int x=0;x<i;x++){
                if(pattern[x]!='*'){dp[i][0]=false;}
            }
        }

        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(pattern[i-1]==text[j-1] || pattern[i-1]=='?'){
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(pattern[i-1]=='*'){
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];

                }else{
                    dp[i][j]=false;
                }
            }
        }
        return dp[n1][n2];
        
    }
};
int main(){
    string pattern = "ab*cd";
    string text = "abdefcd";
    //Output : True
    Solution obj;
    if(obj.isMatch2(text,pattern))cout<<"True";
    else cout<<"False"; 
    return 0;
}