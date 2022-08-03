//https://www.geeksforgeeks.org/maximum-product-cutting-dp-36/
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    int maxProd(int n){
        if(n==0 || n==1){
            return 0;
        }

        int maxi=-1e9;
        for(int i=1;i<n;i++){
            int option=maxProd(n-i)*i;
            maxi=max(maxi,max(i*(n-i),option));
        }
        return maxi;
    }
};
int main(){
    Solution obj;
    //Output : 6
    cout<<obj.maxProd(5)<<endl;
    return 0;
}