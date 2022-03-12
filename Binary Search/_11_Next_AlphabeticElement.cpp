#include<bits/stdc++.h>
using namespace std;

char ceil(string str,int start,int end,char key){
    char result;
    while(start<=end){
        int mid = start+(end-start)/2;
        if(str[mid]==key){
            return str[mid+1];
        }
        else if(str[mid]<key){
            start=mid+1;
        }
        else{
            result=str[mid];
            end=mid-1;
        }
    }
    return result;

}
int main(){
    string str="abdf";
    int size=str.length();
    cout<<ceil(str,0,size-1,'c');
    return 0;
}