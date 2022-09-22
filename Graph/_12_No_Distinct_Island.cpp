//https://practice.geeksforgeeks.org/problems/number-of-distinct-islands/1
//https://youtu.be/7zmgQSJghpo
#include <bits/stdc++.h>
using namespace std;
class Solution {
    void dfs(int i,int j,int basei,int basej,vector<vector<int>>& grid,vector<pair<int,int>>&island){
        if(i>=grid.size() || j>=grid[0].size() || i<0 || j<0){return;}
        if(grid[i][j]==0){return ;}

        grid[i][j]=0;
        //Store the shape of island
        island.push_back({i-basei,j-basej});

        dfs(i-1,j,basei,basej,grid,island); //checkLeft
        dfs(i+1,j,basei,basej,grid,island); //checkRight
        dfs(i,j-1,basei,basej,grid,island); //checkUp
        dfs(i,j+1,basei,basej,grid,island); //checkDown
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        set<vector<pair<int,int>>>set;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    vector<pair<int,int>>island;
                    dfs(i,j,i,j,grid,island);
                    set.insert(island);
                }
            }
        }
        return set.size();
    }
};
int main(){
    vector<vector<int>>grid={{1, 1, 0, 0, 0},
                             {1, 1, 0, 0, 0},
                             {0, 0, 0, 1, 1},
                             {0, 0, 0, 1, 1}};

    Solution obj;
    cout<<obj.countDistinctIslands(grid);
    
    return 0;
}