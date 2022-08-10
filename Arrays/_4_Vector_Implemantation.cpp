#include<bits/stdc++.h>
using namespace std;
class Vector{
    int *arr,n,current;
public:
    Vector(int n=1){
        this->n=n;
        this->current=0;
        arr= new int[n];
    }
    int size(){
        return current;
    }
    int capacity(){
        return n;
    }
    //Add element at last
    void push(int val){
        //If array is full than we need to create new array and move all the elemts to that
        if(current==n){
            n=n*2;
            int *temp = new int[n];
            for(int i=0;i<n;i++){
                temp[i]=arr[i];
            }
            delete[] arr;
            arr=temp;
        }
        arr[current++]=val;
    }
    int get(int index){
        if (index < current){
            return arr[index];
        }
        else{
            throw std::out_of_range("Array out of Bound");
        }
    }
    void pop(){
        current--;
    }
};
int main(){
    Vector ar= Vector();
    ar.push(1);
    ar.push(2);
    ar.push(3);
    ar.pop();
    cout<<ar.capacity()<<endl;    
    for(int i=0;i<ar.size();i++){
        cout<<ar.get(i)<<" ";
    }
    return 0;
}