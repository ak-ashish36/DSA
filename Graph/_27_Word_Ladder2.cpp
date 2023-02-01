//https://leetcode.com/problems/word-ladder-ii/
//https://practice.geeksforgeeks.org/problems/word-ladder-ii/1
//https://youtu.be/DREutrv2XD0
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(),wordList.end());
        queue<vector<string>>q;
        q.push({beginWord});
        vector<vector<string>>ans;
        int level = 0;
        vector<string>usedlevel;
        usedlevel.push_back(beginWord);
        while(!q.empty()){
            vector<string>vec = q.front();
            q.pop();
            if(vec.size()>level){
                level++;
                for(auto it : usedlevel){
                    st.erase(it);
                }
                usedlevel.clear();
            }
            string word = vec.back();
            if(word == endWord){
                if(ans.size()==0){
                    ans.push_back(vec);
                }else if(ans[0].size()==vec.size()){
                    ans.push_back(vec);
                }
            }
            for(int i=0;i<word.length();i++){
                char original = word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    //if exists then append it currect vector
                    if(st.find(word) != st.end()){
                        vec.push_back(word);
                        q.push(vec);
                        usedlevel.push_back(word);
                        vec.pop_back();
                    }
                }
                word[i]=original;
            }
        }
        return ans;
    }
};
int main(){
    string beginWord = "hit";
    string endWord = "cog";
    vector<string>wordList = {"hot","dot","dog","lot","log","cog"};
    Solution obj;
    for(auto it : obj.findLadders(beginWord,endWord,wordList)){
        for(auto j :it){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}