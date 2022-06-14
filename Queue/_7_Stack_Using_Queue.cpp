#include<bits/stdc++.h>
using namespace std;
class Stack{
    queue<int>q1;
    queue<int>q2;
    public:
    bool isEmpty(){
        if(q1.empty())
            return 1;
        return 0;
    }
    void push(int val){
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }

        q1.push(val);

        while(!(q2.empty())){
            q1.push(q2.front());
            q2.pop();
        }
    }
    void pop(){
        if(isEmpty()){
            cout<<"Queue is Empty"<<endl;
            return;
        }
        int pop_elem=q1.front();
        q1.pop();
    }
    int top(){
        if(isEmpty()){
            return -1;
        }
        return q1.front();
    }
};

// Using single Queue
class Stack2{
    queue<int>q;
    public:
    bool isEmpty(){
        if(q.empty())
            return 1;
        return 0;
    }
    void push(int val){
        q.push(val);
        for(int i=0;i<q.size()-1;i++){
            q.push(q.front());
            q.pop();
        }
    }
    void pop(){
        if(isEmpty()){
            cout<<"Queue is Empty"<<endl;
            return;
        }
        int pop_elem=q.front();
        q.pop();
    }
    int top(){
        if(isEmpty()){
            return -1;
        }
        return q.front();
    }
};
int main(){
    Stack2 s;
   
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.pop();
    cout<<s.top()<<endl;
    cout<<s.isEmpty()<<endl;
  
    return 0;
}