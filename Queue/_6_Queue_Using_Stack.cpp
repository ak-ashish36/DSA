#include<bits/stdc++.h>
using namespace std;
// T of push and rear = O(1) , T of pop and front =O(N);
class Queue{
    stack<int>s1;
    stack<int>s2;
    public:
    bool isEmpty(){
        if(s1.empty())
            return 1;
        return 0;
    }
    void push(int val){
        s1.push(val);
    }
    void pop(){
        if(isEmpty()){
            cout<<"Queue is Empty"<<endl;
            return;
        }
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        int pop_elem =s2.top();
        s2.pop();
        while(!(s2.empty())){
            s1.push(s2.top());
            s2.pop();
        }
    }
    int rear(){
        if(isEmpty()){
            return -1;
        }
        return s1.top();
    }
    int front(){
        if(isEmpty()){
            return -1;
        }
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        int front_elem =s2.top();
    
        while(!(s2.empty())){
            s1.push(s2.top());
            s2.pop();
        }
        return front_elem;
    }

};
// T of push and rear = O(N) , T of pop and front =O(1);
class Queue2{
    stack<int>s1;
    stack<int>s2;
    public:
    bool isEmpty(){
        if(s1.empty())
            return 1;
        return 0;
    }
    void push(int val){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(val);

        while(!(s2.empty())){
            s1.push(s2.top());
            s2.pop();
        }
    }
    void pop(){
        if(isEmpty()){
            cout<<"Queue is Empty"<<endl;
            return;
        }
        int pop_elem=s1.top();
        s1.pop();
    }
    int front(){
        if(isEmpty()){
            return -1;
        }
        return s1.top();
    }
    int rear(){
        if(isEmpty()){
            return -1;
        }
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        int front_elem =s2.top();
    
        while(!(s2.empty())){
            s1.push(s2.top());
            s2.pop();
        }
        return front_elem;
    }

};

int main(){
    Queue2 q;
    q.push(5);
    q.push(3);
    q.push(4);
    q.push(9);
    q.push(7);
    
    q.pop();
    q.pop();
    // q.pop();
    // q.pop();
    q.pop();

    cout<<"Front is:"<<q.front()<<endl;
    cout<<"Rear is:"<<q.rear()<<endl;
     
    return 0;
}