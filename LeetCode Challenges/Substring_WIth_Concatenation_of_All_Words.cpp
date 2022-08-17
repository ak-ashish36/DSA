//https://leetcode.com/problems/substring-with-concatenation-of-all-words/
//https://www.interviewbit.com/problems/substring-concatenation/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int>mpp;
        for(auto it :words){
            mpp[it]++;
        }
        int n=words.size();
        int m =words[0].length();
        int len =m*n;
        vector<int>ans;
        
        if(s.length()<len){return ans;}
        
        for(int i=0;i<=s.length()-len;i++){
            unordered_map<string,int>freq=mpp;
            // int j;
            // for(j=0;j<s.length();j++){
            //     string str = s.substr(i+j*m,m);
            //     if(freq[str]==0){
            //         break;
            //     }else{
            //         freq[str]--;
            //     }
            // }
            // if(j==n){
            //     ans.push_back(i);
            // }
            for(int j=i;j<i+len;j+=m){
                string str = s.substr(j,m);
                if(freq.find(str)==freq.end()){
                    break;
                }
                if(freq[str]>1){
                    freq[str]--;
                }else{
                    freq.erase(str);
                }
            }
            if(!freq.size()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
int main(){
    string s = "barfoothefoobarman";
    vector<string> words = {"foo","bar"};
    //Output 0,9
    Solution obj;
    for(int i :obj.findSubstring(s,words)){cout<<i<<" ";}
    return 0;
}