//https://leetcode.com/problems/super-egg-drop/
//https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1
//https://youtu.be/S49zeUjeUL0
#include <bits/stdc++.h>
using namespace std;
class Solution {
    int solve(int e,int f,vector<vector<int>>&dp){
        if(f==0 || f==1){return f;}
        if(e==1){return f;}

        if(dp[e][f]!=-1){return dp[e][f];}
        int mini =1e9;
        // for(int k=1;k<=f;k++){
        //     int breaks = solve(e-1,k-1,dp);
        //     int not_breaks =solve(e,f-k,dp);

        //     int temp = 1+max(breaks,not_breaks);
        //     mini=min(mini,temp); 
        // }

        //Better Time Optimization with help of Binary search approach
        int low=1,high=f;
        while(low<=high){
            int mid = low +(high-low)/2;
            int breaks = solve(e-1,mid-1,dp);
            int not_breaks =solve(e,f-mid,dp);
            int temp = 1+max(breaks,not_breaks);
            mini=min(mini,temp); 

            if(breaks > not_breaks){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return dp[e][f]=mini;
    }
public:
//Memoization
    int superEggDrop(int e, int f) {
        vector<vector<int>>dp(e+1,vector<int>(f+1,-1));
        return solve(e,f,dp);
    }

//Tabulation
    int superEggDrop2(int e, int f) {
        vector<vector<int>>dp(e+1,vector<int>(f+1,0));

        for(int i=1;i<=e;i++){
            for(int j=0;j<=f;j++){
                //Base Case
                if(i==1){dp[i][j]=j;}
                else if(j==1||j==0){dp[i][j]=j;}
                else{
                    int mini =1e9;
                    int low=1,high=j;
                    while(low<=high){
                        int mid = low +(high-low)/2;
                        int breaks = dp[i-1][mid-1];
                        int not_breaks =dp[i][j-mid];
                        int temp = 1+max(breaks,not_breaks);
                        mini=min(mini,temp); 

                        if(breaks > not_breaks){
                            high=mid-1;
                        }else{
                            low=mid+1;
                        }
                    }
                    dp[i][j]=mini;
                }
            }
        }
        return dp[e][f];
    }
};
int main(){
    int e=2,f=6;
    //Output =3
    Solution obj;
    cout<<obj.superEggDrop2(e,f);
    return 0;
}