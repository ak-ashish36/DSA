#include <bits/stdc++.h>
using namespace std;

int shortestSubstring(string s){
    set<char>set;
    for(auto it :s){
        set.insert(it);
    }
    return s.length()-set.size();
}
int main(){
    string s="abcbbk";
    int len=shortestSubstring(s);
    cout<<len;
    return 0;
}