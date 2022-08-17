//https://leetcode.com/problems/longest-string-chain/
//https://www.codingninjas.com/codestudio/problems/longest-string-chain_3752111/
//https://youtu.be/YY8iBaYcc4g
#include <bits/stdc++.h>
using namespace std;
class Solution {
    static bool comp(string &s1 ,string &s2){
        return s1.size()<s2.size();
    }
    bool checkPossible(string s1, string s2){
        if(s1.size()!=s2.size()+1){return false;}
        int first=0,second=0;

        while(first!=s1.size()){
            if(s1[first]==s2[second]){
                first++;
                second++;
            }else{
                first++;
            }
        }
        if(first==s1.size() && second ==s2.size()){return true;}
        return false;
    }
    int solve(int i,int prev,vector<string>& words,vector<vector<int>> &dp){
        // Base Case
        if(i == words.size()){return 0;}

        // DP condition
        if(dp[i][prev+1] != -1){return dp[i][prev+1];}

        int take=0,notTake=0;
        // Not take 
        notTake = 0 + solve(i+1,prev,words,dp);
       // Take if condition met and update previous
        if(prev== -1 ||checkPossible(words[i],words[prev])){
            take = 1+ solve(i+1,i,words,dp);    
        }
        return  max(take,notTake);
    }
public:
    int longestStrChain(vector<string>& words) {
        //Sort words according to words length
        sort(words.begin(),words.end(),comp);
        int n=words.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solve(0,-1,words,dp);  
    }

//T= O(n2) S=O(n)   
    int longestStrChain2(vector<string>&words){
        //Sort words according to words length
        sort(words.begin(),words.end(),comp);
        vector<int> dp(words.size(),1); 
        int maxi=1;
        for(int i=1;i<words.size();i++){
            for(int j=0;j<i;j++){
                if(checkPossible(words[i],words[j])){
                    dp[i]=max(dp[i],dp[j]+1); 
                }
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};
int main(){
    vector<string> words = {"a","b","ba","bca","bda","bdca"};
    //Output = 4["a","ba","bda","bdca"].
    Solution obj;
    cout<<obj.longestStrChain(words);
    return 0;
}