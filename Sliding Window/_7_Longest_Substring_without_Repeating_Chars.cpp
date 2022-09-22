//https://leetcode.com/problems/longest-substring-without-repeating-characters/
//https://practice.geeksforgeeks.org/problems/length-of-the-longest-substring3036/1
//https://youtu.be/qtVh-XEpsJo
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int i=0,j=0;
        int length=-1;
        unordered_map<char,int> m;
        while(j<n){
            m[s[j]]++;
            if(m.size() == j-i+1){
               length=max(length,j-i+1);
            }
            else if(m.size() < j-i+1){
                while(m.size() < j-i+1){
                   m[s[i]]--;
                   if(m[s[i]] == 0) m.erase(s[i]);
                   i++;
                }
            }
            j++;
        }
        return length;
    }
    int longestUniqueSubsttr2(string s){
        // unordered_map<char,int>mpp;
        vector<int>mpp(26,-1);
        int i=0;
        int maxLength=0;
        for(int j=0;j<s.length();j++){
            if(mpp[s[j]-'a']!=-1){
                int prevIndex =mpp[s[j]-'a'];
                if(prevIndex >= i){
                    i=prevIndex+1;
                    //Update the new index
                    mpp[s[j]-'a']=j;
                }
            }
            int newLength=j-i+1;
            maxLength = max(newLength,maxLength);
            mpp[s[j]-'a']=j;
        }
        
        return maxLength;
    }
};
int main(){
    string s="abcabcbb";
    //Output =3 
    Solution obj;
    cout<<obj.lengthOfLongestSubstring(s);
    return 0;
}