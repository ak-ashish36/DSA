#include<bits/stdc++.h>
using namespace std;
void floodfill(vector<vector<int>> arr,int i,int j, vector<vector<bool>> visited, string ans){
    if(i<0 || j<0 || i==arr.size() || j==arr[0].size() || arr[i][j]==1 || visited[i][j]==true){
        return;
    }

    if(i==arr.size()-1 && j==arr[0].size()-1){
        cout<<ans<<" ";
        return;
    }
    visited[i][j]=true;
    floodfill(arr,i-1,j,visited,ans+"t");
    floodfill(arr,i+1,j,visited,ans+"d");
    floodfill(arr,i,j-1,visited,ans+"l");
    floodfill(arr,i,j+1,visited,ans+"r");
    visited[i][j]=false;
}
int main(){
   vector<vector<int>> arr={{0,1,1},{0,0,1},{1,0,0},{0,1,0}} ;
   int row=arr.size();
   int col=arr[0].size();

   vector<vector<bool>> visited(row,vector<bool>(col));

   floodfill(arr,0,0,visited,"");

    return 0;
}