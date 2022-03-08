#include<bits/stdc++.h>
using namespace std;

vector<int>getSubset(vector<int>arr,int index){

    if(index==arr.size()){
        vector<int> sum;
        sum.push_back(0);
        return sum;
    }

    vector<int> rec_sum=getSubset(arr,index+1);

    vector<int>sum;
    for(int i=0;i<rec_sum.size();i++){
        sum.push_back(rec_sum[i]+arr[index]);

    }
    for(int i=0;i<rec_sum.size();i++){
        sum.push_back(rec_sum[i]+0);

    }

    return sum;

}

void printSubset(vector<int>arr,vector<int>&subsetsum,int index,int sum){

    if(index==arr.size()){
        subsetsum.push_back(sum);
        return;
    }
    printSubset(arr,subsetsum,index+1,sum);
    printSubset(arr,subsetsum,index+1,sum+arr[index]);

}

int main(){
    vector<int>arr={1,2,3};

    vector<int>subsetsum =getSubset(arr,0);

    // vector<int>subsetsum;
    // printSubset(arr,subsetsum,0,0);


    sort(subsetsum.begin(),subsetsum.end());

    for(int i:subsetsum){
        cout<<i<<" ";
    }

    return 0;
}