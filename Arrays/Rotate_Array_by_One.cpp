#include<bits/stdc++.h>
using namespace std;
void rotate(vector<int>&arr){
    int n=arr.size();
    int val =arr[n-1];
    for(int i=n-1;i>=0;i--){
        arr[i]=arr[i-1];
    }
    arr[0]=val;
}
int main(){
    vector<int>arr={9, 8, 7, 6, 4, 2, 1, 3};
    rotate(arr);
    for(int i:arr){
        cout<<i<<" ";
    }
    return 0;
}