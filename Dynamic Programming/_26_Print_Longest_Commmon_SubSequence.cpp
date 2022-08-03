//https://youtu.be/-zI4mrF2Pb4
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    string longestCommonSubsequence(string text1, string text2) {
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

        string s="";
        int i=n1,j=n2;

        while(i>=1 && j>=1){
            if(text1[i-1]==text2[j-1]){
                s=text1[i-1]+s;
                i=i-1;
                j=j-1;
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                i=i-1;
            }else{
                j=j-1;
            }  
        }
        return s;
    }
};
int main(){
    string s1="abcde",s2="ace" ;
    //Output : ace
    Solution obj;
    cout<<obj.longestCommonSubsequence(s1,s2); 
    return 0;
}