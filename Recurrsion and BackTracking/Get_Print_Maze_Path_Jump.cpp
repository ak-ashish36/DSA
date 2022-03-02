#include<bits/stdc++.h>
using namespace std;
vector<string> getMazePaths( int i,int j,int r,int c){
    if(i==r && j==c){
        vector<string> ans;
        ans.push_back("");
        return ans;
    }
    
    vector<string> ans;
    for(int jump=1;jump<=c-j;jump++){
        vector<string> h_recans=getMazePaths(i,j+jump,r,c);
        for(int i=0;i<h_recans.size();i++){
            string h="h"+to_string(jump);
            ans.push_back(h+h_recans[i]);
        } 
    }
    for(int jump=1;jump<=r-i;jump++){
        vector<string> v_recans=getMazePaths(i+jump,j,r,c);
        for(int i=0;i<v_recans.size();i++){
            string v="v"+to_string(jump);
            ans.push_back(v+v_recans[i]);
        } 
    }
    for(int jump=1;jump<=r-i && jump<=c-j;jump++){
        vector<string> d_recans=getMazePaths(i+jump,j+jump,r,c);
        for(int i=0;i<d_recans.size();i++){
            string d="d"+to_string(jump);
            ans.push_back(d+d_recans[i]);
        } 
    }
    return ans;
}
// Better Space Complexibility
void printMazePaths(int i,int j,int r,int c,string ans){
    if(i==r && j==c){
        cout<<ans<<" ";
        return;
    }

    for(int jump=1;jump<=c-j;jump++){
        string h="h"+to_string(jump);
        printMazePaths(i,j+jump,r,c,ans+h);
    }
    for(int jump=1;jump<=r-i;jump++){
        string v="v"+to_string(jump);
        printMazePaths(i+jump,j,r,c,ans+v);
    }
    for(int jump=1;jump<=c-j && jump<=r-i;jump++){
        string d="d"+to_string(jump);
        printMazePaths(i+jump,j+jump,r,c,ans+d);
    }

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