#include<bits/stdc++.h>
using namespace std;
 
string reverseWords(string s){

    // temporary vector to store all words
    vector<string> tmp;
    string str = "";
    for (int i = 0; i < s.length(); i++){   
        // Check if we encounter space push word(str) to vector and make str NULL
        if (s[i] == ' '){
            tmp.push_back(str);
            str = "";
        }
        // Else add character to str to form current word
        else
            str += s[i];
    }
    // Last word remaining,add it to vector
    tmp.push_back(str);
    str.clear();
 
    // Now print from last to first in vector
    for (int i = tmp.size() - 1; i >0; i--)
        str+=tmp[i]+" ";
    // Insert last word
    str+=tmp[0];
    return str;
}
int main(){
    string str="Reverse this sentence";
    string s =reverseWords(str);
    cout<<s;
    return 0;
}