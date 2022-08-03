//https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem
#include<bits/stdc++.h>
using namespace std;
int ceil(vector<int>&arr,int target){
    int start=0;int end=arr.size()-1;
    int result=-1;
    while(start<=end){
        int mid = start+(end-start)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]>target){
            result=mid+1;
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return result;
}
vector<int>solution(vector<int>&ranked,vector<int>&player){
    int size=ranked.size();
    int rank[size];
    rank[0]=1;
    vector<int>res;
    for(int i=1;i<size;i++){
        if(ranked[i]==ranked[i-1]){
            rank[i]=rank[i-1];
        }
        else{
            rank[i]=rank[i-1]+1;
        }
    }

    for(int i=0;i<player.size();i++){
        if(player[i]>ranked[0]){
            res.push_back(1);
        }
        else if(player[i]<ranked[size-1]){
            res.push_back(rank[size-1]+1);
        }
        else{
            int index =ceil(ranked,player[i]);
            res.push_back(rank[index]);
        }
    }
    return res;
}
int main(){
    vector<int>ranked={100,100,50,40,40,20,10};
    vector<int>player={5,25,50,120};
    vector<int>ans= solution(ranked,player);
    for(int i :ans){
        cout<<i<<" ";
    }
    return 0;
}