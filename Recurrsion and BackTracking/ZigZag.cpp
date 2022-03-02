#include<bits/stdc++.h>
using namespace std;
void zigzag(int n){
    if (n == 0)
      return;
    cout<<n<<" ";       //Pre
    zigzag(n - 1);
    cout<<n<<" ";       //In
    zigzag(n - 1);
    cout<<n<<" ";       //Post
}
int main(){
    zigzag(2);
    return 0;
}