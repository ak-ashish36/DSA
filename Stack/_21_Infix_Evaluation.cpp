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
int performOperation(stack<int>&operand,stack<char>&operators){
    char c =operators.top();
    operators.pop();

    int a =operand.top();
    operand.pop();

    int b=0;
    if(!operand.empty()){
        b =operand.top();
        operand.pop();
    }
    switch (c) {
        case '+':
            return a + b;
        case '-':
            return b - a;
        case '*':
            return a * b;
        case '/':
            return a / b;
    }
    return 0;
}
int infix_evaluate(string str){
    stack<int>operand;
    stack<char>operators;
    for(int i=0;i<str.length();i++){
        if(str[i]==' '){
            continue;
        }
        else if(str[i]=='('){
            operators.push(str[i]);
        }
        else if(str[i]==')'){
            while(!operators.empty() && operators.top() != '('){
                int output = performOperation(operand, operators);
                operand.push(output);
            }
            operators.pop();
        }
        else if(str[i]=='+'|| str[i]=='-' ||  str[i]=='*' || str[i]=='/'){
            while(!operators.empty() && precedence(operators.top()) >= precedence(str[i]) ){
                int output = performOperation(operand, operators);
                operand.push(output);
            }
            operators.push(str[i]);
        }
        else if(isdigit(str[i])){
            int val=0;
            while(i<str.length() && isdigit(str[i])){
                val = (val*10) + (str[i]-'0');
                i++;
            }
            operand.push(val);
            i--;
        }
    }

    while(!operators.empty()){
        int output = performOperation(operand, operators);
        operand.push(output);
    }
    return operand.top();
}
int main(){
    
    string s="100 * ( 2 + 12 )";
    // string s="1-(-2)";
    cout<<infix_evaluate(s);
    // char c=s[2];
    // int num =int(c)-int('0');
    // cout<<num;
    return 0;
}