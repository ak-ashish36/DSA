#include<bits/stdc++.h>
using namespace std;
// Time Complexity during pop is O(n)
class Queue{
    int *arr,size,rear;  //front will always 0 so no need to write
    public:
    Queue(int size){
        this->size=size;
        arr=new int[size];
        rear=-1;
    }
    bool isFull(){
        if(rear==size-1)
            return 1;
        return 0;
    }
    bool isEmpty(){
        if(rear==-1)
            return 1;
        return 0;
    }
    void push(int val){
        if(isFull()){
            cout<<"Queue is Full"<<endl;
            return;
        }
        rear++;
        arr[rear]=val;
    }
    void pop(){
        if(isEmpty()){
            cout<<"Queue is Empty"<<endl;
            return;
        }
        int pop_elem = arr[0];
        for(int i=0;i<rear;i++){
            arr[i]=arr[i+1];
        }
        rear--;
    }

    int fronte(){
        if(isEmpty())
            return -1;
        return arr[0];
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
    // q.pop();
    // q.pop();
    // q.pop();
    q.pop();

    cout<<"Front is:"<<q.fronte()<<endl;
    cout<<"Rear is:"<<q.reare()<<endl;




    return 0;
}