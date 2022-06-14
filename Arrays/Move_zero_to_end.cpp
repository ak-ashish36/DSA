#include<bits/stdc++.h>
using namespace std;
// T=O(n) S= O(n)
void solution(int arr[],int n){
    int arr2[n];
    int j=n-1;
    int s=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            arr2[j--]=arr[i];
        }
        else{
            arr2[s++]=arr[i];
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr2[i]<<" ";
    }
}
// T=O(n) S= O(1)
void solution2(int arr[],int n){
    int j=0;

    for(int i=0;i<n;i++){
        if (arr[i]!=0){
            swap(arr[i],arr[j++]);
        }
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
//Move all 0s to front
void solution3(int arr[], int n){
	int j = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == 0) {
			swap(arr[i], arr[j++]);
		}
	}
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
   int arr[]={3,1,2,0,0,4,0};
   int n=sizeof(arr)/sizeof(int);
   solution2(arr,n);
    return 0;
}