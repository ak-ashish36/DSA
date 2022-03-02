#include<bits/stdc++.h>
using namespace std;
class Permutation{
    public : 
    void nextpermutation(int nums[],int size){
        int k,l;
        for(k=size-2;k>=0;k--){
            if(nums[k]<nums[k+1]){
                break;
            }
        }
      if(k<0){
          reverse(nums,0,size-1);
      }
      else{
          for(l=size-1;l>k;l--){
              if(nums[l]>nums[k]){
                  break;
              }
          }
        
          swap(nums[k],nums[l]);
       
         reverse(nums,k+1,size-1);

      }
    
    }

    void swap(int &a,int &b){
        int temp =a;
        a=b;
        b=temp;
    }

    void reverse(int A[], int i,int j){
        while(i<j){
            swap(A[i++],A[j--]);
            
        }
          
    }


    
};
int main(){
    int arr[5]={1,3,5,4,2};
    int size = (sizeof(arr)/sizeof(int)); 

    Permutation obj;
    obj.nextpermutation(arr,size);

    for(int i :arr){
        cout<<i<<" ";
    }
   
 
   return 0;
}