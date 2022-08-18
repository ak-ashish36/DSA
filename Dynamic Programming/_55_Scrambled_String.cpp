//https://leetcode.com/problems/scramble-string/
//https://www.codingninjas.com/codestudio/problems/scramble-string_893277/
//https://youtu.be/SqA0o-DGmEw
#include <bits/stdc++.h>
using namespace std;
class Solution {
    bool solve(string s1,string s2,map<string,bool>&dp){
        if(s1==s2){return true;}
        if(s1.length()<=1){return false;}

        string key =s1+" "+s2;
        if(dp.find(key)!=dp.end()){return dp[key];}

        bool scramble=false;
        int n=s1.length();

        for(int i=1;i<n;i++){
            //Let i==2
            //Case 1    gr|eat=> gr  and  rge|at=at    &&       gr|eat=>eat   and  rge|at =rge
            if( solve(s1.substr(0,i),s2.substr(n-i,i),dp) && solve(s1.substr(i,n),s2.substr(0,n-i),dp) ){
                scramble=true;
                break;
            }
            //Case 2   gr|eat=> gr  and  rg|eat=rg         &&       gr|eat=>eat   and  rg|eat =eat
            else if(solve(s1.substr(0,i),s2.substr(0,i),dp) && solve(s1.substr(i,n),s2.substr(i,n),dp) ){
                scramble=true;
                break;
            }
        }
        return dp[key]=scramble;
    }
public:
    bool isScramble(string s1, string s2) {
        if(s1.length()!=s2.length()){return false;}
        map<string,bool>dp;
        return solve(s1,s2,dp);
    }
};
int main(){
    string s1="great";
    string s2="rgeat";
    //Output = true;
    Solution obj;
    cout<<obj.isScramble(s1,s2);
    return 0;
}