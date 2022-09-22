//https://practice.geeksforgeeks.org/problems/replace-os-with-xs0052/1
//https://leetcode.com/problems/surrounded-regions/
//https://youtu.be/BtdgAys4yMk
#include <bits/stdc++.h>
using namespace std;
class Solution{
    void dfs(int i,int j ,vector<vector<char>>& board,vector<vector<int>>& visited){
        if(i>=board.size() || j>=board[0].size() || i<0 || j<0){return;}
        if(visited[i][j]==1 || board[i][j]=='X'){return ;}
        
        visited[i][j]=1;
        
        dfs(i-1,j,board,visited); //checkLeft
        dfs(i+1,j,board,visited); //checkRight
        dfs(i,j-1,board,visited); //checkUp
        dfs(i,j+1,board,visited); //checkDown
    }
public:
    vector<vector<char>> fill(vector<vector<char>>mat){
        int n=mat.size();
        int m=mat[0].size();
        
        vector<vector<int>>visited(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || i==n-1 || j==0 || j==m-1){//Check only 'O' at all 4 boundary
                    if(!visited[i][j] && mat[i][j]=='O'){
                        dfs(i,j,mat,visited);
                    }
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && mat[i][j]=='O'){
                    mat[i][j]='X';
                }
            }
        }
        return mat;
    }
};
int main(){
   vector<vector<char>> mat={{'X', 'X', 'X', 'X'}, 
                            {'X', 'O', 'X', 'X'}, 
                            {'X', 'O', 'O', 'X'}, 
                            {'X', 'O', 'X', 'X'}, 
                            {'X', 'X', 'O', 'O'}};
    /*Output = {{'X', 'X', 'X', 'X'}, 
                {'X', 'X', 'X', 'X'}, 
                {'X', 'X', 'X', 'X'}, 
                {'X', 'X', 'X', 'X'}, 
                {'X', 'X', 'O', 'O'}}; */                       
    Solution obj;
    for(auto it:obj.fill(mat)){
        for(char i:it){cout<<i<<" ";}cout<<endl;
    }
    return 0;
}