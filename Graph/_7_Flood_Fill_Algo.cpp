//https://leetcode.com/problems/flood-fill/
//https://practice.geeksforgeeks.org/problems/flood-fill-algorithm1856/1
//https://youtu.be/C-2_uSRli8o
#include <bits/stdc++.h>
using namespace std;
class Solution {
    void dfs(int i,int j,vector<vector<int>>&image,int color,int iniColor,vector<vector<int>>&visited){
        if(i>=image.size() || j>=image[0].size() || i<0 || j<0){return;}
        if(image[i][j]!=iniColor || visited[i][j]==1){return ;}
        visited[i][j]=1;
        image[i][j]=color;

        dfs(i-1,j,image,color,iniColor,visited); //GoLeft
        dfs(i+1,j,image,color,iniColor,visited); //GoRight
        dfs(i,j-1,image,color,iniColor,visited); //GoUp
        dfs(i,j+1,image,color,iniColor,visited); //GoDown
    }
    
    void bfs(int i,int j,vector<vector<int>>&image,int color,int iniColor,vector<vector<int>>&visited){
        visited[i][j]=1;
        image[i][j]=color;
        queue<pair<int,int>>q;
        q.push({i,j});
        int n=image.size();
        int m=image[0].size();
        vector<int> dr,dc;
        dr = {0,0,-1,1};
        dc = {-1,1,0,0};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int nRow = row + dr[k];
                int nCol = col + dc[k];
                if(nRow>=0 && nCol>=0 && nRow<n && nCol<m && image[nRow][nCol]==iniColor && !visited[nRow][nCol]){
                    visited[nRow][nCol]=1;
                    image[nRow][nCol]=color;
                    q.push({nRow,nCol});
                }  
            }
        }
    }
public:
    vector<vector<int>>floodFill(vector<vector<int>>&image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        int iniColor=image[sr][sc];
        vector<vector<int>>visited(n,vector<int>(m,0));
        bfs(sr,sc,image,color,iniColor,visited);
        return image;
    }
};
int main(){
    vector<vector<int>>image={{1,1,1},{1,1,0},{1,0,1}};
    int sr=1,sc=1,color=2;
    // Output: {{2,2,2},{2,2,0},{2,0,1}}
    Solution obj;
    image=obj.floodFill(image,sr,sc,color);
    for(auto it :image){
        for(auto j :it){cout<<j<<" ";}
        cout<<endl;
    }
    return 0;
}