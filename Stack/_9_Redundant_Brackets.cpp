#include<bits/stdc++.h>
using namespace std;
//Redundant brackets - useless brackets
bool findRedundantBrackets(string &s){
    stack<char> st;
    for(int i=0; i<s.length(); i++) {
        char ch =s[i];
        
        if(ch == '(' || ch == '+' ||ch == '-' || ch == '*' || ch == '/') {
            st.push(ch);
        }
        else if(ch == ')') {
            bool isRedundant = true;
                
            while(st.top() != '(') {
                char top = st.top();
                if(top == '+' ||top == '-' || top == '*' || top == '/') {
                    isRedundant = false;
               }
                st.pop();
            }
            st.pop();
            if(isRedundant == true)
            return true;
        }
    }
    return false;
}
int main(){
    string exp="(a+(a+b))";
    cout<<findRedundantBrackets(exp);
     
    return 0;
}