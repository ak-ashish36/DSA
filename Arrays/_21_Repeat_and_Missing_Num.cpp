//https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1
//https://www.codingninjas.com/codestudio/problems/873366
//https://www.interviewbit.com/problems/repeat-and-missing-number-array/
//https://youtu.be/5nMGY4VUoRY
#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
// T= O(n+n)  S=O(n)
    int *findTwoElement(int *arr, int n) {
        vector<int>freq(n+1,0);

        for(int i=0;i<n;i++){
            freq[arr[i]]++;
        }
        int *ans=new int[2];

        for(int i=1;i<n+1;i++){
            if(freq[i]>1){
                ans[0]=i;
            }
            if(freq[i]==0){
                ans[1]=i;
            }
        }
        return ans;
    }
//Mathematical approach S=O(1) T=O(n)
    int *findTwoElement2(int *arr, int n) {
        long long int Sum = (n * (n+1) ) /2;
        long long int Square = (n * (n +1) *(2*n +1) )/6;

        for(int i=0;i<n; i++){        
            Sum -= arr[i];           //Sum = Sum -(sum of array)
            Square -= arr[i]*arr[i]; //Square = Square -(sum ofsq array)
        }
        
        long long int missingNumber=0, repeating=0;
        // X-Y = Sum-(i)
        // X^2 - Y^2 = Square
        //(X+Y)(X-Y) = Square
        // X+Y = Square/Sum    -(ii)

        // X = Sum+Y        from eq(i)
        // Sum+Y + Y =  Square/Sum
        // 2Y = Square/Sum -Sum
        // Y = (Square/Sum -Sum)/2

        repeating = (Square/Sum -Sum)/2;
        missingNumber =Sum+repeating;
        int *ans=new int[2];
        ans[0]=repeating;
        ans[1]=missingNumber;
        return ans;
    }
};
int main(){
    int arr[]={1,3,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    Solution obj;
    int *ans=obj.findTwoElement2(arr,n);
    cout<<ans[0]<<" "<<ans[1]<<endl;
    return 0;
}