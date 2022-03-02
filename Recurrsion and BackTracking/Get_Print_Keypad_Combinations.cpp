#include<bits/stdc++.h>
using namespace std;
//               0     1     2     3     4     5     6      7    8    9
string codes[]={".;","abc","def","ghi","jkl","mno","pqrs","tu","vwx","yz"};
vector<string> keypadCombination(string str){
    if(str.length()==0){
        vector <string> ans;
        ans.push_back("");
        return ans;
    }
    char c=str[0];
    string next_str =str.substr(1);

    vector<string> rec_ans = keypadCombination(next_str);

    string code_of_c=codes[(int)c-48];
    vector<string> ans;

    for(int i=0;i<code_of_c.length();i++){
        for(int j=0;j<rec_ans.size();j++){
            ans.push_back(code_of_c[i]+rec_ans[j]);
        }
    }

    return ans;
}

// Better Space complexibility
void printCombination(string str,string ans ){
    if(str.length()==0){
        cout<<ans<<" ";
        return;
    }
    char c=str[0];
    string next_str =str.substr(1);

    string code_of_c = codes[(int)c-48];

    for(int i=0;i<code_of_c.length();i++){
        char first_char =code_of_c[i];
        printCombination(next_str,ans+first_char);
    }
}
int main(){
    string str="07";
    vector<string> ans=keypadCombination(str);
    for(string i:ans){
        cout<<i<<" ";
    }
    cout<<"\nBetter Approac Sol\n";
    printCombination(str,"");
    return 0;
}