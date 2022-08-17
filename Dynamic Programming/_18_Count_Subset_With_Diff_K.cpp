//https://leetcode.com/problems/target-sum/
//https://www.codingninjas.com/codestudio/problems/partitions-with-given-difference_3751628/
//https://youtu.be/zoilQD1kYSg?t=446
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:

    //Tabulation
    int countSubsetSum(vector<int>&arr,int k){
        int n=arr.size();
    	vector<vector<int>>dp(n,(vector<int>(k+1,0)));
        
        // Some Modification
        if(arr[0]==0){dp[0][0]=2;}
        else{dp[0][0]=1;}
        if(arr[0]!=0 && arr[0]<=k)dp[0][arr[0]]=1;

        for(int i=1;i<n;i++){
			for(int j=0;j<k+1;j++){
                int not_take=dp[i-1][j];
                int take=0;
				if(arr[i]<=j){
					take=dp[i-1][j-arr[i]];
				}
                dp[i][j]=take + not_take;
			}
		}
		return dp[n-1][k];
    }
    int countPartitions(vector<int>&arr,int d){    // Let s1 and s2 are the two subsets
        int sum=0,count=0;                         // we have to find (s1-s2)=d
        for(int i=0;i<arr.size();i++){             // s1+s2=sum and s1-s2=d
            sum+=arr[i];                           // sum-d = s1+s2-s1+s2
        }                                          //  sum-d =2s2 => s2=sum-d/2
        
        //If sum-d < 0  or sum-d is odd than no partition possible
        if(sum-d<0 || (sum-d)%2)return 0;
        int s2 = (sum-d)/2;
        //countSubset including 0
        return countSubsetSum(arr,s2); 
    }
};

int main(){
    vector<int>arr={0,0,1};
    int d=1;
    //Output : 1
    Solution obj;   
    cout<<obj.countPartitions(arr,d);
    return 0;
}