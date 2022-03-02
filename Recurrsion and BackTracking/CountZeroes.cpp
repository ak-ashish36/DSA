#include<bits/stdc++.h>
using namespace std;
int count(int n,int c){
    if(n/10==0){
        return c;
    }
    if(n%10==0){
        c++;
    }
    return count(n/10,c);
}
int main(){
    cout<<count(200450033,0);
    return 0;
}