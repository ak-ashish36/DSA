#include<bits/stdc++.h>
using namespace std;
int sumOfDigits(int n){
    if(n==0){
        return 0;
    }

    return (n%10) + sumOfDigits(n/10);
}
int proOfDigits(int n){
    if(n%10==n){
        return n;
    }

    return (n%10) * proOfDigits(n/10);
}
int main(){
    cout<<sumOfDigits(1230)<<endl;
    cout<<proOfDigits(1230)<<endl;

    return 0;
}