//https://leetcode.com/problems/word-ladder/
//https://practice.geeksforgeeks.org/problems/word-ladder/1
//https://youtu.be/tRPda0rcf8E
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(),wordList.end());
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        st.erase(beginWord);
        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(word==endWord){
                return steps;
            }
            for(int i=0;i<word.length();i++){
                char original = word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    //if exists in the set than remove it
                    if(st.find(word) != st.end()){
                        st.erase(word);
                        q.push({word,steps+1});
                    }
                }
                word[i]=original;
            }
        }
        return 0;
    }
};
int main(){
    string beginWord = "hit";
    string endWord = "cog";
    vector<string>wordList = {"hot","dot","dog","lot","log","cog"};
    Solution obj;
    cout<<obj.ladderLength(beginWord,endWord,wordList);
    return 0;
}