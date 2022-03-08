#include<bits/stdc++.h>
using namespace std;


void printWords(string str, set<string>set, string ans){

    if(str.length()==0){
        cout<<ans<<endl;
        return;
    }

    for(int i=0;i<str.length();i++){
        string ch=str.substr(0,i+1);
        if(set.find(ch)!=set.end()){
            string rem_str=str.substr(i+1);
            printWords(rem_str,set,ans+ch+" ");

        }
    }

}
int main(){
   string str="microsofthiring";
   set<string>set;
   set.insert("micro"); 
   set.insert("soft"); 
   set.insert("microsoft"); 
   set.insert("hi"); 
   set.insert("ring"); 
   set.insert("hiring"); 

   printWords(str,set,"");

    return 0;
}