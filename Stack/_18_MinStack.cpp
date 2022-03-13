#include<bits/stdc++.h>
using namespace std;
// T=O(n)   S=O(1)
class MinStack {
    int *arr;
    int size;
    int t;
    stack<int>ss;

    public:
    MinStack(int size) {
        this->size=size;
        arr =new int[size];
        t=-1;
    }
    
    void push(int val) {
        if(isFull()){
            cout<<"Stack Overflow"<<endl;
        }
        else{
            if(ss.empty() || val<=ss.top()){
                ss.push(val);
            }
            t++;
            arr[t] = val;
        }
    }
    
    void pop() {
        if(isEmpty()){
            cout<<"Stack Underflow"<<endl;
        }
        else{
            if(ss.top()==arr[t]){
                ss.pop();
            }
            t--;
        }    
    }
    
    int top() {
        if(isEmpty()){
            cout<<"Stack is Empty"<<endl;
            return -1;
        }
        else
            return arr[t]; 
    }
    
    int getMin() {
        if(ss.empty())
            return -1;
        return ss.top();
    }
    bool isEmpty(){
        if(t==-1)
            return 1;
        return 0;
    }
    bool isFull(){
        if(t==size-1)
            return 1;
        return 0;
    }
};
class MinStack2{
    int *arr;
    int size;
    int top_i;
    int min;
    public:
    MinStack2(int size){
        this->size=size;
        arr =new int[size];
        top_i=-1;
    }
    bool isEmpty(){
        if(top_i==-1)
            return 1;
        return 0;
    }
    bool isFull(){
        if(top_i==size-1)
            return 1;
        return 0;
    }
    void push(int val){
        if(isFull()){
            cout<<"Stack Overflow"<<endl;
        }
        else{
            if(isEmpty()){
                top_i++;
                arr[top_i] = val;
                min=val;
            }
            else if(val<min){
                top_i++;
                arr[top_i]=(2*val)-min;
                min=val;
            }
            else{
                top_i++;
                arr[top_i] = val;
            }
        }
    }  
    void pop(){
        if(isEmpty()){
            cout<<"Stack Underflow"<<endl;
        }
        else{
            if(arr[top_i]<min){
                min=(2*min)-arr[top_i];
            }
            top_i--;
        }
    } 

    int top(){
        if(isEmpty()){
            return -1;
        }
        else{
            if(arr[top_i]<min){
                return min;
            }else{
                return arr[top_i];
            }
        }
    }
    int getMin(){
        return min;
    }
};
int main(){
    MinStack2 s(5);
   
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    cout<<s.top()<<endl;
    cout<<s.getMin();
    return 0;
}