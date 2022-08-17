//https://leetcode.com/problems/maximal-rectangle/
//https://practice.geeksforgeeks.org/problems/max-rectangle/1
//https://www.codingninjas.com/codestudio/problems/maximum-size-rectangle-sub-matrix-with-all-1-s_893017/
#include<bits/stdc++.h>
using namespace std;
vector<int> nearestSmallerRightIndex(vector<int>arr){
    int size=arr.size();
    vector<int>ans;
    stack<pair<int,int>>s;
    for(int i=arr.size()-1;i>=0;i--){
        if(s.empty()){
            ans.push_back(size);
        }
        else if(s.top().first<arr[i]){
            ans.push_back(s.top().second);
        }

        else if(s.top().first>=arr[i]){
            while(!s.empty() && s.top().first>=arr[i]){
                s.pop();
            }
            if(s.empty())
                ans.push_back(size);
            else
                ans.push_back(s.top().second);
        }
        s.push(make_pair(arr[i],i));
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
vector<int> nearestSmallerLeftIndex(vector<int>arr){
    vector<int>ans;
    stack<pair<int,int>>s;
    for(int i=0;i<arr.size();i++){
        if(s.empty()){
            ans.push_back(-1);
        }
        else if(s.top().first<arr[i]){
            ans.push_back(s.top().second);
        }

        else if(s.top().first>=arr[i]){
            while(!s.empty() && s.top().first>=arr[i]){
                s.pop();
            }
            if(s.empty())
                ans.push_back(-1);
            else
                ans.push_back(s.top().second);
        }
        s.push(make_pair(arr[i],i));
    }
    return ans;
}

int maxHistogramArea(vector<int>arr){
    vector<int>right_index=nearestSmallerRightIndex(arr);
    vector<int>left_index=nearestSmallerLeftIndex(arr);

    vector<int>width;
    for(int i=0;i<arr.size();i++){
        width.push_back(right_index[i]-left_index[i]-1);
    }

    vector<int>area;
    for(int i=0;i<arr.size();i++){
       area.push_back(width[i]*arr[i]);
    }

    int max=*max_element(area.begin(),area.end());
    return max;
}
int maxAreaRectangle(vector<vector<int>>arr){
    int m=arr.size();
    int n=arr[0].size();

    vector<int>v;
    for(int j=0;j<n;j++){
        v.push_back(arr[0][j]);
    }
    
    int maximum =maxHistogramArea(v);

    for(int i=1;i<m;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]==0){
                v[j]=0;
            }
            else{
                v[j]=v[j]+arr[i][j];
            }
        }
        maximum=max(maximum,maxHistogramArea(v));
    }

    return maximum;

}
int main(){
    vector<vector<int>>arr={{0,1,1,0},
                            {1,1,1,1},
                            {1,1,1,1},
                            {1,1,0,0}};
    cout<<maxAreaRectangle(arr);
    return 0;
}