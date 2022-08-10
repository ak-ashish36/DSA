//https://practice.geeksforgeeks.org/problems/reverse-an-array/0
//https://www.codingninjas.com/codestudio/problems/reverse-the-array_1262298
#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    //Time : O(2n)  Space : O(n)
    void reverse(int arr[],int n){
        int temp[n];
        int j=0;
        for(int i=n-1;i>=0;i--){
            temp[j++]=arr[i];
        }
        for(int i=0;i<n;i++){
            arr[i]=temp[i];
        }
    }

    //Time : O(n/2)  Space : O(1)
    void reverse2(int arr[],int n){
        int i=0,j=n-1;
        while(i<j){
            swap(arr[i++],arr[j--]);
        }
    }
};
int main(){
    int arr[]={1,2,3,4,5,6,7,8,9};
    int n = sizeof(arr)/sizeof(int);
    Solution obj;
    obj.reverse2(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}