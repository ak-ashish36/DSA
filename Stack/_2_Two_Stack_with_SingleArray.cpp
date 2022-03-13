#include<bits/stdc++.h>
using namespace std;
class Stack{
    int *arr;
    int size;
    int top1;
    int top2;

    public:
    Stack(int size){
        this->size=size;
        arr =new int[size];
        top1=-1;
        top2=size;
    }
    bool isFull(){
        if(top2-top1<=1)
            return 1;
        return 0;
    }
    bool isEmpty1(){
        if(top1==-1)
            return 1;
        return 0;
    }
    bool isEmpty2(){
        if(top2==size)
            return 1;
        return 0;
    }  
    
    void push1(int val){
        if(isFull()){
            cout<<"Stack Overflow"<<endl;
        }
        else{
            top1++;
            arr[top1] = val;
        }
    }
    void push2(int val){
        if(isFull()){
            cout<<"Stack Overflow"<<endl;
        }
        else{
            top2--;
            arr[top2] = val;
        }
    }    
    void pop1(){
        if(isEmpty1()){
            cout<<"Stack Underflow"<<endl;
        }
        else{
            top1--;
        }
    }
    void pop2(){
        if(isEmpty2()){
            cout<<"Stack Underflow"<<endl;
        }
        else{
            top2++;
        }
    }  

    int Size1(){
        return top1+1;
    }
    int Size2(){
        return size-top2;
    }
    int peek1(){
        if(isEmpty1()){
            cout<<"Stack is Empty"<<endl;
            return -1;
        }
        else
            return arr[top1];
    } 
    int peek2(){
        if(isEmpty2()){
            cout<<"Stack is Empty"<<endl;
            return -1;
        }
        else
            return arr[top2];
    }  
};
int main(){
    Stack s(5);
   
   s.push1(1);
   s.push1(2);
   s.push1(3);

   s.push2(8);
   s.push2(9);
   s.push2(1);  //overflow

   s.pop1();
   s.pop1();

    cout<<s.Size1()<<endl;
    cout<<s.Size2()<<endl;

    cout<<s.peek1()<<endl;
    cout<<s.peek2()<<endl;

   cout<<s.isFull()<<endl;



    return 0;
}