#include<bits/stdc++.h>
using namespace std;
vector<string> getMazePaths( int i,int j,int r,int c){
    if(i==r && j==c){
        vector<string> ans;
        ans.push_back("");
        return ans;
    }
    if(i>r || j>c){
        vector<string> ans;
        return ans;
    }

    vector<string> h_recans=getMazePaths(i,j+1,r,c);
    vector<string> v_recans=getMazePaths(i+1,j,r,c);

    vector<string> ans;
    for(int i=0;i<h_recans.size();i++){
        ans.push_back("h"+h_recans[i]);
    } 
    for(int i=0;i<v_recans.size();i++){
        ans.push_back("v"+v_recans[i]);
    }

    return ans;
}
// Better Space Complexibilty
void printMazePaths(int i,int j,int r,int c,string ans){
    if(i==r && j==c){
        cout<<ans<<" ";
        return;
    }
    if(i>r || j>c){
        return;
    }
    printMazePaths(i,j+1,r,c,ans+"h");
    printMazePaths(i+1,j,r,c,ans+"v");
}
int main(){
    int source_i=0,source_j=0;
    int des_i=2,des_j=2;
    vector <string> ans=getMazePaths(source_i,source_j,des_i,des_j);
    for(string i :ans){
        cout<<i<<" ";
    }
    cout<<"\nBetter Approac Sol\n";
    printMazePaths(source_i,source_j,des_i,des_j,"");
    return 0;
}