//https://leetcode.com/problems/set-matrix-zeroes/
#include<bits/stdc++.h>
using namespace std;

void setZeroes(vector < vector < int >> &matrix){
int rows = matrix.size();
int cols = matrix[0].size();
for (int i = 0; i < rows; i++) {
    for (int j = 0; j <cols; j++) {
     if (matrix[i][j]==0){
          int ind_j = j - 1;
          while (ind_j >= 0) {
            if (matrix[i][ind_j] != 0) {
              matrix[i][ind_j] = -1;

            }
          ind_j--;
        }
        ind_j=j+1;
         while(ind_j<cols){
           if(matrix[i][ind_j]!=0){matrix[i][ind_j]=-1;}
             ind_j++;
         }

         int ind_i = i - 1;
        while (ind_i >= 0) {
          if (matrix[ind_i][j] != 0) {
            matrix[ind_i][j] = -1;
          }
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
//Better approach
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
int main() {
  vector < vector < int >> arr;
  arr = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
  // setZeroes(arr);
  setZeroes2(arr);
  cout << "The Final Matrix is " << endl;
  for (int i = 0; i < arr.size(); i++) {
    for (int j = 0; j < arr[0].size(); j++) {
      cout << arr[i][j] << " ";
    }
    cout << "\n";
  }

}