//https://leetcode.com/problems/shortest-common-supersequence/
//https://www.codingninjas.com/codestudio/problems/shortest-supersequence_4244493
//https://youtu.be/xElxAuBcvsU
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
    int lengthShortestCommonSupersequence(string str1, string str2) {
        int n1=str1.length();
        int n2=str2.length();
        vector<vector<int>>dp(n1,vector<int>(n2,-1));

        int longestCommonSubSeq=lcs(n1-1,n2-1,str1,str2,dp);

        return n1+n2-longestCommonSubSeq;
    }
    string shortestCommonSupersequence(string str1, string str2) {
        int n1=str1.length(),n2=str2.length();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));

        for(int i=0;i<=n1;i++){         //Index right shifting is done to handle the base case 
            for(int j=0;j<=n2;j++){
                if(i==0 || j==0){
                    dp[i][j]=0;
                }else{
                    if(str1[i-1]==str2[j-1]){
                        dp[i][j] = 1 +dp[i-1][j-1];
                    }else{
                        dp[i][j] = 0 + max(dp[i-1][j] , dp[i][j-1]);
                    }
                }
            }
        }
        //Upto here same code as Print longest subSequence
        string ans="";
        int i=n1,j=n2;
        while(i>=1 && j>=1){
            if(str1[i-1]==str2[j-1]){
                ans+=str1[i-1];
                i=i-1;
                j=j-1;
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                ans+=str1[i-1];
                i=i-1;
            }else{
                ans+=str2[j-1];
                j=j-1;
            }  
        }
        while(i>0){ans+=str1[i-1];i--;}
        while(j>0){ans+=str2[j-1];j--;}

        return string(ans.rbegin(),ans.rend());
    }
};
int main(){
    string s1="brute",s2="groot";
    //Output : bgruoote
    Solution obj;
    cout<<"Length : "<<obj.lengthShortestCommonSupersequence(s1,s2)<<endl; 
    cout<<"Ans : "<<obj.shortestCommonSupersequence(s1,s2)<<endl; 

    return 0;
}