//https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1
//https://youtu.be/Lav6St0W_pQ
#include <bits/stdc++.h>
using namespace std;
class Solution{
  public:
    int longestKSubstr(string s, int k) {
        int n=s.size();
        int i=0,j=0;
        int length=-1;
        unordered_map<char,int> m;
        while(j<n){
           m[s[j]]++;
           if(m.size() == k){
               length=max(length,j-i+1);
           }
           else if(m.size() > k){
               while(m.size() > k){
                   m[s[i]]--;
                   if(m[s[i]] == 0) m.erase(s[i]);
                   i++;
               }
           }
           j++;
        }
        return length;
    }
};
int main(){
    string s="aabacbebebe";
    int k=3;
    //Output = 7  {cbebebe}
    Solution obj;
    cout<<obj.longestKSubstr(s,k);
    return 0;
}