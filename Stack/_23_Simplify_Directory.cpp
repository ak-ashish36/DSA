//https://leetcode.com/problems/simplify-path/submissions/
#include<bits/stdc++.h>
using namespace std;
string simplify(string str){
    stack<string>st;
    for(int i=0;i<str.length();i++){
        string path="";
        while(i<str.length() && str[i]!='/'){
            path+=str[i];
            i++;
        }
        if(path=="." || path=="") continue;
        else if(path==".."){
            if(!st.empty()){
                st.pop();
            }
        }
        else{
            st.push(path);
        }
    }
    if(st.size()==0)return "/";
    string ans="";
    while(!st.empty()){
        ans="/"+st.top()+ans;
        st.pop();
    }
    return ans;
}
int main(){
    string s="/home//foo/";
    cout<<simplify(s);
    return 0;
}