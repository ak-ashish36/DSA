//https://leetcode.com/problems/4sum/
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> duplicate =nums;
        int size=duplicate.size();
        sort(duplicate.begin(),duplicate.end());
        for(int i=0;i<size;i++){
            for(int j=i+1;j<size;j++){
                int target_2=target-duplicate[i]-duplicate[j];
                int left=j+1, right=size-1;
                while(left<right){
                    if(duplicate[left]+duplicate[right]==target_2){
                        vector<int> quadruplet(4, 0);
                        quadruplet[0] = duplicate[i];
                        quadruplet[1] = duplicate[j];
                        quadruplet[2] = duplicate[left];
                        quadruplet[3] = duplicate[right];
                        ans.push_back(quadruplet);
                        while (left < right && duplicate[left] == quadruplet[2]) ++left;
                        while (left < right && duplicate[right] == quadruplet[3]) --right;
                    }
                    else if(duplicate[left]+duplicate[right]>target_2){
                        right--;
                    }
                    else if(duplicate[left]+duplicate[right]<target_2){
                        left++;
                    }
                }
                while(j+1 < size && duplicate[j + 1] == duplicate[j]) ++j;
            }   
                while (i+1 < size && duplicate[i + 1] == duplicate[i]) ++i;
        }
        duplicate.clear();
        return ans;
}
int main(){
    vector<int> arr={1,0,-1,0,-2,2};
    vector<vector<int>>ans=fourSum(arr,0);
    for(vector<int> i:ans){
        for(int j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
   return 0;
}