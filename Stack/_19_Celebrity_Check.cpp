#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    private:
    bool knows(vector<vector<int> >& M, int a, int b, int n) {
        if(M[a][b] == 1)
            return true;
        else
            return false;
    }
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> s;
        //step1: push all element in stack
        for(int i=0; i<n; i++) {
            s.push(i);
        }   
        
        //step2: get 2 elements and compare them
        
        while(s.size() > 1) {
            
            int a = s.top();
            s.pop();
            
            int b = s.top();
            s.pop();
            
            if(knows(M,a,b,n)){
                s.push(b);
            }
            else
            {
                s.push(a);
            }
        }
        int ans = s.top();
        //step3: single element in stack is potential celeb
        //so verify it
        
        //Row check
        int zeroCount = 0;
        for(int i=0; i<n; i++) {
            if(M[ans][i] == 0)
                zeroCount++;
        }
        //all zeroes
        if(zeroCount != n){
            return -1;
        }
        
        //column check
        int oneCount = 0;
        for(int i=0; i<n; i++) {
            if(M[i][ans] == 1 && M[ans][ans]==0)
                oneCount++;
        }
        
        if(oneCount != n-1){
            return -1;
        }
        return ans;  
    }
};
int main(){
    vector<vector<int>> arr={{0,1,0},
                             {0,0,0},
                             {0,1,0}};
    int n=arr.size();
    Solution ob;
    cout<<ob.celebrity(arr,n)<<endl;
}