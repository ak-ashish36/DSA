//https://leetcode.com/problems/powx-n/
#include<bits/stdc++.h>
using namespace std;
double myPow(double x, int n) {
    double ans = 1.0;
    if(x==1){return 1;}
    if(n<0){x=1/x;n=(-1*n);}  
    for (int i = 0; i < n; i++) {
        ans = ans * x;
    }
    return ans;    
}
// Better approach o(logn)
double myPow2(double x, int n) {
    double ans = 1.0;
    if(x==1){return 1;}
    if(n<0){x=1/x;n=(-1*n);}  
    while(n) {
        if (n % 2) { // n is odd
        ans = ans * x;
        n = n - 1;
        } else { // n is even
            x = x * x;
            n = n / 2;
        }
    }
    return ans;
}
int main(){
    // myPow(2.00,10);
    double answer=myPow(2,-3);
    cout<<answer;

   return 0;
}