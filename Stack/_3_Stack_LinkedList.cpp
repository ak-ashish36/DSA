#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *down;
    Node(int data=0){
        this->data=data;
        this-> down=nullptr;
    }
};
class StackList{
    Node *top;
    public:
    StackList(){
        top=NULL;
    }
    bool isEmpty(){
        if(top==NULL)
            return 1;
        return 0;
    }
    
    bool isFull(){
        Node*newnode=new Node();
        if(newnode==NULL)
            return 1;
        return 0;
    }
    void push(int val){
        if(isFull()){
            cout<<"Stack Overflow"<<endl;
            return;
        }
        Node*newnode=new Node(val);
        newnode->down=top;
        top=newnode;
    }
    void pop(){
        if(isEmpty()){
            cout<<"Stack Underflow"<<endl;
            return;
        }
        Node*newnode=top;
        top=top->down;
        delete(newnode);
    }
    int peek(){
        if(isEmpty()){
            cout<<"Stack is Empty"<<endl;
            return -1;
        }
        return top->data;
    }
    void display(){
        if(isEmpty()){
            cout<<"Stack is Empty"<<endl;
            return;
        }
        Node * temp=top;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->down;
        }
        cout<<endl;
    }

};
int main(){
    StackList s;
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);

    s.pop();

    // cout<<s.isEmpty()<<endl; 
    // cout<<s.isFull()<<endl; 
    cout<<s.peek()<<endl;
    s.display();

    return 0;
}