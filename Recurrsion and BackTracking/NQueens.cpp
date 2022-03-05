#include<bits/stdc++.h>
using namespace std;

bool safetyCheck(vector<vector<int>>chess,int row,int col){
    //Cheching upper row
    for(int i=row-1,j=col; i>=0 ;i--){
        if(chess[i][j]==1)
            return false;
    }
    //Cheching left diagonal
    for(int i=row-1,j=col-1; i>=0 && j>=0 ;i--,j--){
        if(chess[i][j]==1)
            return false;
    }
    //Cheching right diagonal
    for(int i=row-1,j=col+1; i>=0 && j<chess.size() ;i--,j++){
        if(chess[i][j]==1)
            return false;
    }
    return true;
}
void printNQueens(vector<vector<int>>chess,int row,string ans){
    if(row==chess.size()){
        cout<<ans<<".";
        cout<<endl;
        return;
    }

    for(int col=0;col<chess.size();col++){
        if(safetyCheck(chess,row,col)){
            chess[row][col]=1;
            string new_ans=ans+to_string(row)+"-"+to_string(col)+",";
            printNQueens(chess,row+1,new_ans);
            chess[row][col]=0;
        }
    }
}
int main(){
   vector<vector<int>>chess(4,vector<int>(4,0));
    printNQueens(chess,0,"");
    return 0;
}