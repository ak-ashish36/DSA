//https://leetcode.com/problems/rotting-oranges/
//https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1
//https://youtu.be/yf3oUhkvqA0
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));

        queue<pair<int,int>>q;
        int freshOranges = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    visited[i][j]=1;
                }
                if(grid[i][j]==1){freshOranges++;}
            }
        }

        int rottenOranges = 0;
        int time =0;
        int delRow[]={-1,0,1,0};
        int delCol[]={0,-1,0,1};
        while(!q.empty()){
            int size =q.size();
            while(size--){
                int row=q.front().first;
                int col=q.front().second;
                q.pop();
                for(int k=0;k<4;k++){
                    int nRow=row+delRow[k];
                    int nCol=col+delCol[k];
                    if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && grid[nRow][nCol]==1 && !visited[nRow][nCol]){
                        q.push({nRow,nCol});
                        visited[nRow][nCol]=1;
                        rottenOranges++;
                    }
                }
            }
            if(!q.empty())time++;
        }
        if(freshOranges != rottenOranges){return -1;}
        return time;
    }
};
int main(){
    vector<vector<int>>grid = {{2,1,1},
                               {1,1,0},
                               {0,1,1}};
    //Output = 4
    Solution obj;
    cout<<obj.orangesRotting(grid);
    return 0;
}