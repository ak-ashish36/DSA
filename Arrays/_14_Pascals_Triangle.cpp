//https://leetcode.com/problems/pascals-triangle/
//https://www.codingninjas.com/codestudio/problems/pascal-s-triangle_1089580
//https://practice.geeksforgeeks.org/problems/pascal-triangle0652/1
//https://youtu.be/6FLvhQjZqvM
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pas_triangle;
        pas_triangle.push_back({1});
        if(numRows==1)
        return pas_triangle;
        pas_triangle.push_back({1,1});
        for(int i=2;i<numRows;i++){
            vector<int> v;
            v.push_back(1);
            for(int j=0;j<=i-2;j++){
                v.push_back(pas_triangle[i-1][j]+pas_triangle[i-1][j+1]);
            }
            v.push_back(1);
            pas_triangle.push_back(v);
        }
        return pas_triangle; 
    }
};
int main(){
    Solution obj;
    vector<vector<int>> arr =obj.generate(5);
    for(vector<int> vect1D : arr){
        for (int x : vect1D){
            cout << x << " ";
        }   
        cout << endl;
    }
   return 0;
}
// Formula ot get mth row and nth column elemnet = mCn =fact(m)/fact(m-n)*fact(n)