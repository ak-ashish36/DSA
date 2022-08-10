//https://leetcode.com/problems/set-matrix-zeroes/
//https://www.codingninjas.com/codestudio/problems/set-matrix-zeros_3846774/
//https://www.interviewbit.com/problems/set-matrix-zeros/
//https://youtu.be/M65xBewcqcI
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  // T :O((N*M)*(N + M))+O(N*M)   and  S: O(1)
    void setZeroes(vector<vector<int>>& matrix){
      int rows = matrix.size();
      int cols = matrix[0].size();

      for(int i = 0; i < rows; i++){

        for (int j = 0; j <cols; j++){

          if (matrix[i][j]==0){

            int ind_j = j - 1;
            while (ind_j >= 0) {
              if (matrix[i][ind_j] != 0) {matrix[i][ind_j] = -1;}
              ind_j--;
            }
            ind_j=j+1;
            while(ind_j<cols){
              if(matrix[i][ind_j]!=0){matrix[i][ind_j]=-1;}
              ind_j++;
            }

            int ind_i = i - 1;
            while (ind_i >= 0) {
              if (matrix[ind_i][j] != 0) {matrix[ind_i][j] = -1;}
              ind_i--;
            }
            ind_i=i+1;
            while(ind_i<rows){
             if(matrix[ind_i][j]!=0){matrix[ind_i][j]=-1;}
             ind_i++;
            }
          }
        }  
      }

      for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
          if (matrix[i][j] == -1) {
            matrix[i][j] = 0;
          }
        }
      } 
    }

// T= O(N*M + N*M) and S =O(n)
  void setZeroes2(vector < vector < int >> &matrix){
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector <int> temp1(rows,-1),temp2(cols,-1);
  
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j <cols; j++) {
        if (matrix[i][j]==0){
          temp1[i]=0;
          temp2[j]=0;
        }
      }
    }
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j <cols; j++) {
        if (temp1[i]==0 || temp2[j]==0){
          matrix[i][j]=0;
        }
      }
    }
  }

//T =O(2*(N*M)) and S=O(1)
  void setZeroes3(vector < vector < int >> & matrix) {
    int col0 = 1, rows = matrix.size(), cols = matrix[0].size();

    for (int i = 0; i < rows; i++) {
    //checking if 0 is present in the 0th column or not
      if (matrix[i][0] == 0) col0 = 0;
      for (int j = 1; j < cols; j++) {
        if (matrix[i][j] == 0) {
          matrix[i][0] = 0;
          matrix[0][j] = 0;
        }
      }
    }
    //traversing in the reverse direction and checking if the row or col has 0 or not
    //and setting values of matrix accordingly.
    for (int i = rows - 1; i >= 0; i--) {
      for (int j = cols - 1; j >= 1; j--) {
        if (matrix[i][0] == 0 || matrix[0][j] == 0) {
          matrix[i][j] = 0;
        }
      }
      if (col0 == 0) {
        matrix[i][0] = 0;
      }
    }
  }
};

int main() {
  vector <vector<int>>arr={{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
  Solution obj;
  obj.setZeroes2(arr);
  for(auto i : arr){
    for(int j :i){
      cout<<j<<" ";
    }
    cout<<endl;
  }

}