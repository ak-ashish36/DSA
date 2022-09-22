//https://practice.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1
//https://leetcode.com/problems/find-all-anagrams-in-a-string/
//https://youtu.be/MW4lJ8Y0xXk
#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
	int search(string txt, string pat) {
	    unordered_map<char,int>mpp;
        for(auto it:pat){mpp[it]++;}
        int count =mpp.size();

        int k=pat.length();
        int i=0,j=0;
        int ans=0;
        for(j=0;j<txt.length();j++){
            if(mpp.find(txt[j])!=mpp.end()){
                mpp[txt[j]]--;
                if(mpp[txt[j]]==0){
                    count--;
                }
            }
            
            if(j-i+1==k){
                if(count==0){ans++;}
                if(mpp.find(txt[i])!=mpp.end()){
                    mpp[txt[i]]++;
                    if(mpp[txt[i]]==1){count++;}
                }
                i++;
            }
        }
        return ans;
	}
};
int main(){
    string txt = "forxxorfxdofr";
    string pat="for";
    //Output = 3 {for,orf,ofr}
    Solution obj;
    cout<<obj.search(txt,pat);
    return 0;
}