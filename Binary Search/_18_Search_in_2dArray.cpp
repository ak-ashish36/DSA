////https://leetcode.com/problems/search-a-2d-matrix-ii/
#include<bits/stdc++.h>
using namespace std;
pair<int,int>binarySearch2D(int arr[][4],int row,int col,int target){
    int i=0;
    int j=col-1;

    pair<int,int>p(-1,-1);

    while(i>=0 && i<row && j>=0 && j<col){
        if(arr[i][j]==target){

            p.first=i,p.second=j;
            return p;
        }
        else if(arr[i][j]>target){
            j--;
        }
        else{
            i++;
        }
    }
    return p;
}
int main(){
    int arr[][4]={{10,20,30,40},
                 {15,25,35,45},
                 {27,29,37,48},
                 {32,33,39,50}};

    int col=sizeof(arr[0])/sizeof(int);
    int row=sizeof(arr)/sizeof(int)/col;
    
    pair<int,int>ans=binarySearch2D(arr,row,col,33);
    cout<<ans.first<<" "<<ans.second<<endl;

    return 0;
}   