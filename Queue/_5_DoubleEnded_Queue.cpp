#include<bits/stdc++.h>
using namespace std;
// Time Complexity during pop is O(1)
class Dequeue{
    int *arr,size,front,rear;
    public:
    Dequeue(int size){
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
    void push_rear(int val){
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
    void push_front(int val){
        if(isFull()){
            cout<<"Queue is Full"<<endl;
            return;
        }
        if(front==-1 && rear==-1){
            front++,rear++;
            arr[front]=val;
        }
        else{
            if(front==0){
                front=size-1;
                arr[front]=val;
            }
            else{
                front--;
                arr[front]=val;
            }
        }
    }
    void pop_front(){
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
    
    void pop_rear(){
        if(isEmpty()){
            cout<<"Queue is Empty"<<endl;
            return;
        }
        int pop_elem=arr[rear];
        if(front==rear){
            front=rear=-1;
        }
        else{
            if(rear==0){
                rear=size-1;
            }
            else{
                rear--;
            }
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
    Dequeue q(7);
    q.push_rear(6);
    q.push_front(3);
    q.push_rear(8);
    q.push_front(9);
    q.push_rear(7);
    q.push_front(4);

    q.pop_front();
    q.pop_rear();


    cout<<q.fronte()<<endl;
    cout<<q.reare()<<endl;



    return 0;
}