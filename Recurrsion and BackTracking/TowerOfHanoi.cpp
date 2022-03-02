#include<bits/stdc++.h>
using namespace std;
void towerOfHanoi(int n,char TA,char TB,char TC){
    if(n==0){return;}
    towerOfHanoi(n-1,TA,TC,TB);
    cout<<n<<":"<<TA<<"->"<<TB<<endl;
    towerOfHanoi(n-1,TC,TB,TA);
}
int main(){
    towerOfHanoi(3,'A','B','C');
    return 0;
}