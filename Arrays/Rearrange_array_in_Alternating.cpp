#include<bits/stdc++.h>
using namespace std;
// T= O(n)  S= O(n)
void rearrange(int arr[],int n){
    vector<int>pos,neg;
    for(int i=0;i<n;i++){
        if(arr[i]<0){
            neg.push_back(arr[i]);
        }
        else{
            pos.push_back(arr[i]);
        }
    }
    int i=0,j=0,k=0;
    while(j<pos.size() && k<neg.size()){
        if(i==0 || arr[i-1]>0){
            arr[i++]=neg[k++];
        }
        if(arr[i-1]<0){
            arr[i++]=pos[j++];
        }
    }
    while(j<pos.size()){
        arr[i++]=pos[j++];
    }
    while(k<neg.size()){
        arr[i++]=pos[k++];
    }
}
void rightrotate(int arr[],int outofplace, int cur){
    char tmp = arr[cur];
    for (int i = cur; i > outofplace; i--)
        arr[i] = arr[i - 1];
    arr[outofplace] = tmp;
}
// T= O(n)  S= O(1)
void rearrange2(int arr[],int n){
    int wrongIndex=-1;
    for(int i=0;i<n;i++){
        if(wrongIndex==-1){
            if( (arr[i]<0 && i%2==1) || (arr[i]>=0 && i%2==0) ){
                wrongIndex=i;
            }
        }
        else{
            if( (arr[wrongIndex]>=0 && arr[i]<0) || (arr[wrongIndex]<0 && arr[i]>=0) ){
                rightrotate(arr,wrongIndex,i);
                if (i - wrongIndex >= 2) wrongIndex+=2;
                else wrongIndex = -1;
            }
        }
    }
}
int main(){
    int arr[] = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8};
    int n= sizeof(arr)/sizeof(int);
    rearrange2(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}