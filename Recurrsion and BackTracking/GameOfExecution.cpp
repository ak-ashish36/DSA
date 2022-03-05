#include<bits/stdc++.h>
using namespace std;
int survived(int n,int k){
    if(n==1){
        return 0;
    }
    int x=survived(n-1,k);
    int y=(x+k)%n;
    return y;

}

int ans(){
    int count=0;
    for(int i=100;i<=999;i++){
        if(i%6==0){
            count++;
        }
    }
    return count;
}
int main(){
    // cout<<survived(7,4);
    cout<<ans();
    return 0;
}