#include<bits/stdc++.h>
using namespace std;
   
void generatePalidrome(map<char,int>mpp,int index,int len, char oddc, string ans){
    if(index>len){
        string rev=ans;
        reverse(rev.begin(),rev.end());
        string finalans=ans+oddc+rev;
        cout<<finalans<<" ";
        return;
        
    }

    for(auto i:mpp){
        int freq=i.second;
        if(freq>0){
            mpp[i.first]=freq-1;
            generatePalidrome(mpp,index+1,len,oddc,ans+i.first);
            mpp[i.first]=freq;
        }
    }
}


void printPalidromicPermutation(string str){
    
    map<char,int>mpp;
    for(int i=0;i<str.length();i++){
       char ch=str[i];
       mpp[ch]++;
    }
    char oddc=NULL;
    int odds=0;
    int len=0;

    for(auto i:mpp){
       int freq=i.second;
       if(freq%2==1){
           oddc=i.first;
           odds++;
       }
       mpp[i.first]=freq/2;
       len+=freq/2;
   }

    if(odds>=2){
       cout<<"Palidrome not possible";
    }
    else{
        generatePalidrome(mpp,1,len,oddc,"");
    }
}
int main(){
    string str="aabb";
    printPalidromicPermutation(str);
    return 0;
}