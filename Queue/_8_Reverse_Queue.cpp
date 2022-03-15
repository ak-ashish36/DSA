#include<bits/stdc++.h>
using namespace std;
queue<int> rev(queue<int> q){
    stack<int> s;
    
    while(!q.empty()) {
        int element = q.front();
        q.pop();
        s.push(element);
    }

    while(!s.empty()) {
        int element = s.top();
        s.pop();
        q.push(element);
    }
    return q;
}
void rev2(queue<int>&q){
    if(q.empty()){
        return;
    }
    int x=q.front();
    q.pop();
    rev2(q);
    q.push(x);
}
int main(){
    queue<int> q;
    q.push(1);
    q.push(2); 
    q.push(3);
    q.push(4);

    // cout<<q.front()<<endl;
    // queue <int> ans=rev(q);
    // cout<<ans.front()<<endl;

    cout<<q.front()<<endl;
    rev2(q);
    cout<<q.front()<<endl;



    return 0;
}