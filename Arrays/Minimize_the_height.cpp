#include<bits/stdc++.h>
using namespace std;
int getMinDiff(int arr[], int n, int k) {
        // code here
        sort(arr,arr+n);
        int ans = arr[n-1]-arr[0];
        
        int lowest = arr[0]+k;
        int greatest = arr[n-1]-k;
        int mi,ma;
        
        for(int i=0;i<n;i++){
            mi = min(lowest,arr[i+1]-k);
            ma = max(greatest,arr[i]+k);
            if(mi<0){
                continue;
            }
            ans=min(ans,ma-mi);
        }
        
        return ans;    
}

int main(){
    int arr[]={2,6,3,4,7,2,10,3,2,1};
    int n=sizeof(arr)/sizeof(int);
    cout<<getMinDiff(arr,n,5);
     
    return 0;
}