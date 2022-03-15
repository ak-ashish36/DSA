#include<bits/stdc++.h>
using namespace std;
class Queue{
    struct Node{
        int data;
        Node *next;
        Node(int data=0){
            this->data=data;
            this-> next=nullptr;
        }
    };
    int front,rear;
    Node *head,*tail;
    public:
    Queue(){
        head=NULL;
        tail=NULL;
    }
    bool isEmpty(){
        if(head==NULL)
            return 1;
        return 0;
    }
    void push(int val){
        Node*newnode=new Node(val);
        if(head==NULL && tail==NULL){
            head=newnode;
            tail=newnode;
        }else{
            tail->next=newnode;
            tail =newnode;
        }
    }
    void pop(){
        if(isEmpty()){
            cout<<"Queue is Empty"<<endl;
            return;
        }
        head=head->next;
    }
    int fronte(){
        if(isEmpty())
            return -1;
        return head->data;
    }
    int reare(){
        if(isEmpty())
            return -1;
        return tail->data;
    }

};


int main(){
    Queue q;
    q.push(5);
    q.push(3);
    q.push(4);
    q.push(9);
    q.push(7);
    
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();


    cout<<"Front is:"<<q.fronte()<<endl;
    cout<<"Rear is:"<<q.reare()<<endl;
     
    return 0;
}