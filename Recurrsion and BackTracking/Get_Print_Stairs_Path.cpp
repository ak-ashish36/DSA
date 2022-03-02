#include<bits/stdc++.h>
using namespace std;
vector<string> getPath(int n){
    if(n==0){
        vector<string> ans;
        ans.push_back("");
        return ans;
    }
    if(n<0){
        vector<string> ans;
        return ans;
    }

    vector<string> rec1_ans=getPath(n-1);
    vector<string> rec2_ans=getPath(n-2);
    vector<string> rec3_ans=getPath(n-3);

    vector<string> ans;
    for(string i:rec1_ans){
        ans.push_back('1'+i);
    }
    for(string i:rec2_ans){
        ans.push_back('2'+i);
    }
    for(string i:rec3_ans){
        ans.push_back('3'+i);
    }

    return ans;
}
// Better Space Complexibility
void printPath(int n,string ans){
    if(n==0){
        cout<<ans<<" ";
        return;
    }
    if(n<0){
        return;
    }

    printPath(n-1,ans+"1");
    printPath(n-2,ans+"2");
    printPath(n-3,ans+"3");
}
int main(){
    vector<string> ans;
    ans=getPath(4);
    for(string i:ans){
        cout<<i<<" ";
    }
    cout<<"\nBetter Approac Sol\n";
    printPath(4,"");
    return 0;
}