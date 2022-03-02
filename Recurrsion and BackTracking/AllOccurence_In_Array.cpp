#include<bits/stdc++.h>
using namespace std;
vector<int>allOccurenceInArray(int arr[],int size,int target,int index){
    if(index==size){
        vector<int> ans;
        return ans;
    }
    if(arr[index]==target){
         vector<int>ans;
         ans=allOccurenceInArray(arr,size,target,index+1);
         ans.push_back(index);

        return ans;
    }
    else{
        vector<int> ans=allOccurenceInArray(arr,size,target,index+1);
        return ans;
    }
}
int main(){
    int arr[]={1,2,9,4,5,9,8};
    int n= sizeof(arr)/sizeof(int);
    int target=9;
    vector<int> ans=allOccurenceInArray(arr,n,target,0); 
    for(int i :ans){
        cout<<i<<" ";
    }

    return 0;
}