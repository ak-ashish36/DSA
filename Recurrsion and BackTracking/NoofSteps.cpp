#include<bits/stdc++.h>
using namespace std;
int noOfSteps(int n,int c){
    if(n==0){
        return c;
    }
    if(n%2==0){
        c++;
        n=n/2;
    }
    else{
        c++;
        n=n-1;
    }
    return noOfSteps(n,c);
}
int main(){
    cout<<noOfSteps(41,0);
    return 0;
}