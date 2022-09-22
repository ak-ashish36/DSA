//https://leetcode.com/problems/minimum-window-substring/
//https://practice.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1
//https://youtu.be/iwv1llyN6mo
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        if(t.length()>s.length()){return "";}
        int n=s.length();
        map<char,int>mpp;
        for(int i=0;i<t.length();i++){
            mpp[t[i]]++;
        }
        int count=mpp.size();
        int i=0,j=0;
        string ans=s;
        bool found=false;
        while(j<n){
            if(mpp.find(s[j])!=mpp.end()){
                mpp[s[j]]--;
                if(mpp[s[j]]==0){count--;}
            }
            if(count==0){
                while(count==0){
                    if(mpp.find(s[i])!=mpp.end()){
                        mpp[s[i]]++;
                        if(mpp[s[i]]==1){
                            count++;
                            if(ans.length()>=j-i+1){
                                found=true;
                                ans=s.substr(i,j-i+1);
                            }
                        }
                    }
                    i++;
                }
            }
            j++;
        }
        if(!found){ans="";}
        return ans;
    }
};
int main(){
    string s = "a", t = "a";
    Solution obj;
    cout<<obj.minWindow(s,t);
    return 0;
}