#include<bits/stdc++.h>
using namespace std;
void printNQueens(vector<vector<int>>chess,bool colm[],bool diag[],bool Rdiag[],int row,string ans){
    if(row==chess.size()){
        cout<<ans<<".";
        cout<<endl;
        return;
    }

    for(int col=0;col<chess[0].size();col++){
        if(colm[col]==false && diag[row+col]==false && Rdiag[row-col +chess.size()-1]==false){
            chess[row][col]=1;
            colm[col]=true;
            diag[row+col]=true;
            Rdiag[row-col +chess.size()-1]=true;

            string new_ans=ans+to_string(row)+"-"+to_string(col)+",";
            printNQueens(chess,colm,diag,Rdiag,row+1,new_ans);

            chess[row][col]=0;
            colm[col]=false;
            diag[row+col]=false;
            Rdiag[row-col +chess.size()-1]=false;

        }
    }


}
int main(){
    vector<vector<int>>chess(4,vector<int>(4,0));
    bool col[4]={};
    bool diag[chess.size()*2 -1]={};
    bool Rdiag[chess.size()*2 -1]={};
    
    printNQueens(chess,col,diag,Rdiag,0,"");
    return 0; 
    return 0;
}