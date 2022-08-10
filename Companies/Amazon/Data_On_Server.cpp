//https://www.chegg.com/homework-help/questions-and-answers/1-code-question-1-amazon-stores-data-different-servers-different-locations-time-time-due-s-q93774001#question-transcript
//https://youtu.be/GSdRohHWnCM
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    vector<int> findDataLocations(vector<int>locations,vector<int>movedFrom, vector<int>movedTo){

        set<int>set;
        for(int i=0;i<locations.size();i++){
            set.insert(locations[i]);
        }

        for(int i=0;i<movedFrom.size();i++){
            if(movedFrom[i]!=movedTo[i]){
                set.erase(movedFrom[i]);
                set.insert(movedTo[i]);
            }
        }
        vector<int>ans;
        for(auto it:set){
            cout<<it<<" ";
        }
        return ans;
    }
};
int main(){
    vector<int>locations ={1,7,6,8};
    vector<int>movedFrom ={1,7,2};
    vector<int>movedTo ={2,9,5};
    //Output : {5,6,8,9}
    Solution obj;
    vector<int>ans=obj.findDataLocations(locations,movedFrom,movedTo);
    for(int i:ans){cout<<i<<" ";}
    return 0;
}