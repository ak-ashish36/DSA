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
void print(vector<int>arr){
    for(int i:arr){
        cout<<i<<" ";
    }
    cout<<endl;
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

    print(right_index);
    print(left_index);
    print(width);
    print(area);

    int max=*max_element(area.begin(),area.end());
    return max;
}
int main(){
    vector<int> arr={6,2,5,4,5,1,6};

    cout<<maxHistogramArea(arr);
    return 0;
}