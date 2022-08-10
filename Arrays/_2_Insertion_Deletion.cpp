#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    //Time : O(n)  Space : O(1)
    void insertAt(int arr[],int n,int val, int index){
        if(index>=n){
            cout<<"Index out of Bound can't insert at "<<index<<endl;
            return;
        }
        //Shift all the element right from last to index
        for(int i=n-1;i>index;i--){
            arr[i]=arr[i-1];
        }
        //After shift just insert the value at given index
        arr[index]=val;
    }

    //Time : O(n)  Space : O(1)
    void deleteAt(int arr[],int n,int index){
        //Shift all the element to left from index upto last
        for(int i=index;i<n;i++){
            arr[i]=arr[i+1];
        }
    }
};
int main(){
    int arr[10]={1,2,3,4,5,6,7,8};
    int n = sizeof(arr)/sizeof(int);
    for(int i : arr){cout<<i<<" ";}cout<<endl;
    Solution obj;
    //Insertion
    obj.insertAt(arr,n,7,2); 
    obj.insertAt(arr,n,14,9);
    for(int i : arr){cout<<i<<" ";}cout<<endl;
    obj.insertAt(arr,n,12,10);
    obj.insertAt(arr,n,12,0);
    for(int i : arr){cout<<i<<" ";}cout<<endl;
    //Deletion
    obj.deleteAt(arr,n,3);
    for(int i : arr){cout<<i<<" ";}cout<<endl;

    return 0;
}