//https://www.interviewbit.com/problems/evaluate-expression/
#include<bits/stdc++.h>
using namespace std;
int evaluate(vector<string>&tokens){
    stack<int> st;
    for(int i = 0; i < tokens.size(); ++i) {
        if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
            int v1=st.top();
            st.pop();
            int v2=st.top();
            st.pop();
            switch(tokens[i][0]) {
                case '+':
                    st.push(v2 + v1);
                    break;
                case '-':
                    st.push(v2 - v1);
                    break;
                case '*':
                    st.push(v2 * v1);
                    break;
                case '/':
                    st.push(v2 / v1);
                    break;
            }
        } else {
            st.push(stoi(tokens[i]));
        }
    }
    return st.top();
}
int main(){
    vector<string>str={"2", "1", "+", "3","*"};
    cout<<evaluate(str);
    return 0;
}