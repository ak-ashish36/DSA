//https://practice.geeksforgeeks.org/problems/sum-of-elements-between-k1th-and-k2th-smallest-elements3133/1
//https://youtu.be/3ioQQQrnw4Q
#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    int sumBetweenTwoKth(vector<int>arr,int K1,int K2){
        int n=arr.size();
        priority_queue<int>maxH;
        int K =max(K1,K2);

        for(int i=0;i<n;i++){
            maxH.push(arr[i]);
            if(maxH.size()>K){
                maxH.pop();
            }
        }

        int y=maxH.top();
        int k=min(K1,K2);
        while(maxH.size()!=k){
            maxH.pop();
        }
        int x =maxH.top();

        int sum =0;
        for(int i=0;i<n;i++){
            if(arr[i]>x && arr[i]<y){
                sum+=arr[i];
            }
        }
        return sum;
    }
};
int main(){
    vector<int>arr={20,8,22,4,12,10,14};
    int k1=3,k2=6;
    //Output =26 {10-> 12,14 <-20}
    Solution obj;
    cout<<obj.sumBetweenTwoKth(arr,k1,k2);
    return 0;
}