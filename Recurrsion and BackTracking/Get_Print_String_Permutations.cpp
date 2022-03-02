#include<bits/stdc++.h>
using namespace std;

vector<string>getPermutaion(string str){

    if(str.length()==0){
        vector <string>ans;
        ans.push_back("");
        return ans;
    }

    vector<string>ans;
    for(int i=0;i<str.length();i++){
        char c=str[i];
        string rem_str=str.substr(0,i)+str.substr(i+1);
        
        vector <string> rec_ans=getPermutaion(rem_str);

        for(int i=0;i<rec_ans.size();i++){
            ans.push_back(c+rec_ans[i]);
        }

    }
    return ans;

}
// Better Solution
void printPermutaion(string str,string ans){

    if(str.length()==0){
        cout<<ans<<" ";
        return;
    }

    for(int i=0;i<str.length();i++){
        char c=str[i];
        string rem_str=str.substr(0,i)+str.substr(i+1);
        printPermutaion(rem_str,ans+c);
    }

}
int main(){
    string str="abc";
    vector<string> ans=getPermutaion(str);
    for(string i:ans){
        cout<<i<<" ";
    }
    cout<<"\nBetter Approac Sol\n";
    printPermutaion("abc","");
    return 0;
}