//https://leetcode.com/problems/longest-substring-without-repeating-characters/
#include<bits/stdc++.h>
using namespace std;
// T=O(2n) S=O(n)
int lengthOfLongestSubstring(string s) {
        unordered_set<int>set;
        int lenght=0;
        int l=0;
        for(int r=0;r<s.length();r++){
            if(set.find(s[r])!=set.end()){
                while(l<r && set.find(s[r])!=set.end()){
                    set.erase(s[l]);
                    l++;
                }
            }
            int newLenght=r-l+1;
            lenght=max(newLenght,lenght);
            set.insert(s[r]);
        }
        return lenght;
}
// T=O(n) S=O(n)
int lengthOfLongestSubstring2(string s) {
        unordered_map<char,int>map;
        int lenght=0;
        int l=0;
        for(int r=0;r<s.length();r++){
            if(map.find(s[r])!=map.end()){
                if(map[s[r]]>=l){
                    l=map[s[r]]+1;
                    map[s[r]]=r;
                }
            }
            int newLenght=r-l+1;
            lenght=max(newLenght,lenght);
            map[s[r]]=r;
        }
        return lenght;
}
int main(){
    string s="abcdabcf";
    cout<<lengthOfLongestSubstring(s);
   return 0;
}