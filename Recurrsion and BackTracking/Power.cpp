#include<bits/stdc++.h>
using namespace std;
double power(double x,int n){
    if(n<0){x=1/x;n=(-1*n);}
    if(n==0){return 1;}
    double ans=x*power(x,n-1);
    return ans;
}
double power2(double x,int n){
    if(n<0){x=1/x;n=(-1*n);}
    if(n==0){return 1;}

    double ans=1;
    
    if(n%2==0){       // n i even
        x=x*x;
        n=n/2;
    }else{           // n is odd
        ans=ans*x;
        n=n-1;
    }

    ans=ans*x*power(x,n-1);
    return ans;
}
int main(){
    double answer=power2(2,4);
    cout<<answer;
    return 0;
}