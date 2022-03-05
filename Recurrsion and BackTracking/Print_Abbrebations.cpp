#include<bits/stdc++.h>
using namespace std;

void printAbbrebations(string str,int i,int count,string ans){
    if(i==str.length()){
        if(count==0){
            cout<<ans<<" ";
        }
        else{
            cout<<ans+to_string(count)<<" ";
        }
        return;
    }

    //previous ans is added to new ans count becomes 0
    if(count>0)
        printAbbrebations(str,i+1,0,ans+to_string(count)+str[i]);
    else
        printAbbrebations(str,i+1,0,ans+str[i]);

    //previous ans is not added to new ans count increases
    printAbbrebations(str,i+1,count+1,ans);


}
int main(){
    string s="pep";
    printAbbrebations(s,0,0,"");
    
    return 0;
}