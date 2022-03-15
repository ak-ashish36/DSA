#include<bits/stdc++.h>
using namespace std;
int precedence(char ch){
    if(ch == '^'){
        return 3;
    }
    else if(ch == '*' || ch=='/')
        return 2;
    else if(ch == '+' || ch=='-')
        return 1; 
    else
        return 0;
}
string infixToPostfix(string infix){
    stack<int> s;

    string postfix;
    
    for(int i=0;i<infix.length();i++){
        if(infix[i]>='a' && infix[i]<='z' || infix[i]>='A' && infix[i]<='Z'){
            postfix.push_back(infix[i]);
        }
        else if(infix[i]=='('){
            s.push(infix[i]);
        }
        else if(infix[i]==')'){
            while(!s.empty() && s.top() !='('){
                postfix.push_back(s.top());
                s.pop();
            }
            s.pop();  //remove opening bracket
        }
        else{
            while(!s.empty() && precedence(s.top()) >= precedence(infix[i]) ){
                postfix.push_back(s.top());
                s.pop();
            }
            s.push(infix[i]);
        }
    }
    
    while (!s.empty()){
        postfix.push_back(s.top());
        s.pop();
    }
    return postfix;
}
int main(){
     string str ="a+b*(c^d-e)^(f+g*h)-i";
     cout<<infixToPostfix(str);
    return 0;
}