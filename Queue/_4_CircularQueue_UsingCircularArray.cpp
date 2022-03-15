#include<bits/stdc++.h>
using namespace std;
// Time Complexity during pop is O(1)
class Queue{
    int *arr,size,front,rear;
    public:
    Queue(int size){
        this->size=size;
        arr=new int[size];
        front=-1;
        rear=-1;
    }
    bool isFull(){
        if((rear+1)%size==front)
            return 1;
        return 0;
    }
    bool isEmpty(){
        if(front==-1 && rear==-1)
            return 1;
        return 0;
    }
    void push(int val){
        if(isFull()){
            cout<<"Queue is Full"<<endl;
            return;
        }
        if(front==-1 && rear==-1){
            front++,rear++;
        }else{
            rear=(rear+1)%size;;
        }

        arr[rear]=val;
    }
    void pop(){
        if(isEmpty()){
            cout<<"Queue is Empty"<<endl;
            return;
        }
        int pop_elem=arr[front];
        if(front==rear){
            front=rear=-1;
        }
        else{
            front=(front+1)%size;
        }
    }

    int fronte(){
        if(isEmpty())
            return -1;
        return arr[front];
    }
    int reare(){
        if(isEmpty())
            return -1;
        return arr[rear];
    }

};
int main(){
    Queue q(5);
    q.push(5);
    q.push(3);
    q.push(4);
    q.push(9);
    q.push(7);
    
    q.pop();
    q.pop();
    // q.pop();
    // q.pop();
    // q.pop();

    cout<<"Front is:"<<q.fronte()<<endl;
    cout<<"Rear is:"<<q.reare()<<endl;




    return 0;
}