#include<bits/stdc++.h>
using namespace std;
bool match(char a, char b){
    if(a=='{' && b=='}'){
        return 1;
    }
    if(a=='(' && b==')'){
        return 1;
    }
    if(a=='[' && b==']'){
        return 1;
    }
  return 0;  
}

int parenthesisMatch(string exp){
    
    stack<char>sp;
   
    for (int i = 0;i<exp.length(); i++){
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='['){
            sp.push(exp[i]);
        }
        else if(exp[i]==')'|| exp[i]=='}' || exp[i]==']'){
            if(sp.empty()){
                return 0;
            }
            char popped_ch = sp.top();
            sp.pop();
            if(!match(popped_ch, exp[i])){ 
              return 0;  
            }
        }
    }

    if(sp.empty()){
        return 1;
    }
    else{
        return 0;
    }
    
}
int main(){
    string exp="[4-6]((8){(9-8)})";
    cout<<parenthesisMatch(exp);
    return 0;
}