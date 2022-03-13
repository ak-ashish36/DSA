#include<bits/stdc++.h>
using namespace std;
void insertAtBottom(stack<int>&s,int x){
    //base case
    if(s.empty()) {
        s.push(x);
        return ;
    }
    
    int num = s.top();
    s.pop();
    
    //recursive call
    insertAtBottom(s, x);
    s.push(num);

}
void reverseStack(stack<int>&s){
    if(s.empty()){
        return;
    }
    int num = s.top();
    s.pop();
    
    //recursive call
    reverseStack(s);
    
    insertAtBottom(s,num);
}
void printStack(stack<int>s){
    int size=s.size();
    for(int i=0;i<size;i++){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}
int main(){
    stack<int>s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    printStack(s);
    reverseStack(s);
    printStack(s);     
    return 0;
}