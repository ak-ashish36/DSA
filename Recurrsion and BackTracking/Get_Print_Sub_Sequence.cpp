#include<bits/stdc++.h>
using namespace std;
vector<string> getSubSequence(string s){
    if(s.length()==0){
        vector<string>ans;
        ans.push_back("");
        return ans;
    }
    char ch=s[0];
    string rem_s=s.substr(1);
    vector<string>rec_ans=getSubSequence(rem_s);

    vector<string>ans;
    for(int i=0;i<rec_ans.size();i++){
        ans.push_back(""+rec_ans[i]);
    }
    for(int i=0;i<rec_ans.size();i++){
        ans.push_back(ch+rec_ans[i]);
    }
    
    return ans;
}

// Better Space Complexibility
void printSubSequence(string s,string ans){
    if(s.length()==0){
        cout<<ans<<" ";
        return;
    }
    char ch=s[0];
    string rem_s=s.substr(1);

    printSubSequence(rem_s,ans+ch);
    printSubSequence(rem_s,ans);    
}
int main(){
    string str ="abc";
    vector<string>ans=getSubSequence(str);
    for(string i:ans){
        cout<<i<<" ";
    }
    cout<<"\nBetter Approac Sol\n";
    printSubSequence(str,"");
    return 0;
}