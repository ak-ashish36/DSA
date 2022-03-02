#include<bits/stdc++.h>
using namespace std;
int sum=0;
void reverse(int n){
    if(n==0){
        return;
    }
    int rem=n%10;
    sum=sum*10+rem;
    reverse(n/10);
}

int reversing(int n,int digits){
    if(n%10==n){
        return n;
    }
    int rem=n%10;    
    return  rem*pow(10,digits-1) + reversing(n/10,digits-1);
}
int reverse2(int n){
    int digits=5;
    return reversing(n,digits);
}
int main(){
    // reverse(1234);
    // cout<<sum<<endl;
    cout<<reverse2(25364);
    return 0;
}