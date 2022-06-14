
#include<bits/stdc++.h>
using namespace std;
int solution(vector<int>&arr,int k){
    priority_queue <int, vector<int>, greater<int> > minh;
    for(int i=0;i<arr.size();i++){
        minh.push(arr[i]);
        if(minh.size()>k){
            minh.pop();
        }
    }

    return minh.top();
}
int main(){
    vector<int>arr={3,2,3,1,2,4,5,5,6};

    cout<<solution(arr,4);
     
    return 0;
}