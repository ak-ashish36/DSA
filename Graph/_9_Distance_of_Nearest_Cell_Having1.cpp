//https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1
//https://leetcode.com/problems/01-matrix/
//https://youtu.be/edXdVwkYHF8
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>>nearest(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,-1));

        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    visited[i][j]=0;
                }
            }
        }
        int step = 0;
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
                    if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && grid[nRow][nCol]==0 && visited[nRow][nCol]==-1){
                        q.push({nRow,nCol});
                        visited[nRow][nCol]=step+1;
                    }
                }
            }
            if(!q.empty())step++;
        }
        return visited;
    }
};
int main(){
    vector<vector<int>>grid={{0,1,1,0},
                            {1,1,0,0},
                            {0,0,1,1}};
    
    Solution obj;
    for(auto it :obj.nearest(grid)){
        for(int i:it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}