#include<bits/stdc++.h>
using namespace std;


void print(vector<vector<int>>chess){
    for(vector<int> i :chess){
        for(int j :i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void knightsTour(vector<vector<int>>chess,int row,int col,int move){
if(row<0 || col<0 || row>=chess.size() || col>=chess.size() || chess[row][col]>0){
    return;
}
else if(move==chess.size()*chess.size()){
    chess[row][col]=move;
    print(chess);
    chess[row][col]=0;
    return;
}

chess[row][col]=move;
knightsTour(chess,row-2,col+1,move+1);
knightsTour(chess,row-1,col+2,move+1);
knightsTour(chess,row+1,col+2,move+1);
knightsTour(chess,row+2,col+1,move+1);

knightsTour(chess,row+2,col-1,move+1);
knightsTour(chess,row+1,col-2,move+1);
knightsTour(chess,row-1,col-2,move+1);
knightsTour(chess,row-2,col-1,move+1);
chess[row][col]=0;

}
int main(){
   vector<vector<int>>chess(7,vector<int>(7,0));
    knightsTour(chess,0,2,1);
    return 0;
}