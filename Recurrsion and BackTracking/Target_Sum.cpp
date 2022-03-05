#include<bits/stdc++.h>
using namespace std;
void printTargetSum(vector<int>arr,int i,int target,int sum, string ans){
    if(i==arr.size()){
        if(sum==target){
            cout<<ans;
            cout<<endl;
        }
        return;
    }
    
    string new_ans=ans+to_string(arr[i])+",";
    int new_sum=sum+arr[i];
    printTargetSum(arr,i+1,target,new_sum,new_ans);
    printTargetSum(arr,i+1,target,sum,ans);

}

int main(){
   vector<int> arr={10,20,30,40,50};
   int target =70; 
   printTargetSum(arr,0,70,0,"");
    return 0;
}