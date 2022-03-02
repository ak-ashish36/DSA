// https://leetcode.com/problems/rotate-image/
#include<bits/stdc++.h>
using namespace std;
void print_matrix(vector<vector<int>>& matrix);

void rotate(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector < vector < int >> matrix2(rows, vector < int > (cols, 0));
    int size=rows-1;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            matrix2[j][size] = matrix[i][j];
         
        }
        size--;
    }
    print_matrix(matrix2);
}
// Optimal Solution with less 0(1) space complexibility
void rotate2(vector<vector<int>>& matrix){
    int rows = matrix.size();
    // Transpose of matrix
    for(int i=0;i<rows;i++){
        for(int j=0;j<i;j++){
            swap(matrix[i][j],matrix[j][i]);
         
        }
    }
    //Reversing every row
    for(int i=0;i<rows;i++){
        reverse(matrix[i].begin(),matrix[i].end());
    }
    print_matrix(matrix);
}

void print_matrix(vector<vector<int>>& matrix){
    for(auto r: matrix){
        for(auto c :r){
            cout<<c<<" ";
        }
        cout<<endl;
    }
}

int main(){
    vector<vector<int>>matrix;
    matrix={{1,2,3},{4,5,6},{7,8,9}};
    cout<<"Before Rotating"<<endl;
    print_matrix(matrix);
    cout<<"After Rotating"<<endl;
    rotate2(matrix);

   return 0;
}