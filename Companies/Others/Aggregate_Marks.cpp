#include<bits/stdc++.h>
using namespace std;

struct Result{
    int output[3];
};

Result output(vector<vector<int>>arr,int N,int M){
    int min=INT_MAX;
    int x;
    for(int i=0;i<M;i++){
        int sum=0;
        for(int j=0;j<N;j++){           // Getting sum of marks all students(rows) of each subjet(column)
            sum+=arr[j][i];
        }
        if(sum<min){                    // Comparing sum of all columns and storing the index and sum of minimun column
            min=sum;
            x=i;
        }
    }

    Result r;
    int k=0;
    for(int i=0;i<N;i++){               // Getting the total marks of each student by excluding the minimun marks column
        int sum=0;
        for(int j=0;j<M;j++){
            if(j==x){continue;}
            sum+=arr[i][j];
        }
        r.output[k++]=sum;
    }
    return r;
}
int main(){
    vector<vector<int>>arr={{70,30,40,50},                  // 3 students  with 4 subjects
                            {30,50,40,90},
                            {60,70,80,90}};

    Result r= output(arr,3,4);

    for(int i :r.output){
        cout<<i<<" ";
    }
    return 0;
}