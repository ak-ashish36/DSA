#include<bits/stdc++.h>
using namespace std;
int solution(vector<int>&arr,int k){
    priority_queue<int>maxh;
    for(int i=0;i<arr.size();i++){
        maxh.push(arr[i]);
        if(maxh.size()>k){
            maxh.pop();
        }
    }

    return maxh.top();
}
int main(){
    vector<int>arr={3,2,2,3,1,2,4,5,5,6};
    cout<<solution(arr,4);
    return 0;
}