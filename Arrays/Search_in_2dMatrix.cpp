//https://leetcode.com/problems/search-a-2d-matrix/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(auto r: matrix){
            for(auto c :r){
                if(c==target){return true;} 
             }
        }
        return false;
    }
    // Better Optimization using binary search (only applicable if array is sorted)
    bool searchMatrix2(vector<vector<int>>& matrix, int target){
        int row= matrix.size(),col=matrix[0].size();
        int low=0,high=(row*col)-1;
        if(!row){return false;}
        while(low<=high){
            int mid =(low+high)/2;
            if(matrix[mid/col][mid%col]==target){return true;}
            else if(matrix[mid/col][mid%col]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }  
        }
        return false;
    }
};
int main(){
    vector<vector<int>> matrix;
    matrix={{1,3,5,7},
            {10,11,16,20},
            {23,30,34,60}};
    Solution obj;
    bool result =obj.searchMatrix2(matrix,34);
    cout<<result;

    
   return 0;
}