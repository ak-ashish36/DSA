#include<bits/stdc++.h>
using namespace std;
class Stack{
    int *arr;
    int size;
    int top;
    public:
    Stack(int size){
        this->size=size;
        arr =new int[size];
        top=-1;
    }
    bool isEmpty(){
        if(top==-1)
            return 1;
        return 0;
    }
    bool isFull(){
        if(top==size-1)
            return 1;
        return 0;
    }
    void push(int val){
        if(isFull()){
            cout<<"Stack Overflow"<<endl;
        }
        else{
            top++;
            arr[top] = val;
        }
    }  
    void pop(){
        if(isEmpty()){
            cout<<"Stack Underflow"<<endl;
        }
        else{
            top--;
        }
    } 

    int Size(){
        return top+1;
    }
    int peek(){
        if(isEmpty()){
            cout<<"Stack is Empty"<<endl;
            return -1;
        }
        else
            return arr[top];
    }  
};
int main(){
    Stack s(5);
   
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    cout<<s.isFull()<<endl;
    cout<<s.peek()<<endl;
    cout<<s.isEmpty()<<endl;
    cout<<s.Size()<<endl;
  
    Stack s2(2);
    s2.push(77);
    cout<<s2.peek()<<endl;
    cout<<s2.Size()<<endl;


    return 0;
}