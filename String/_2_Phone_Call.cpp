#include<bits/stdc++.h>
using namespace std;
string getPhoneNumber(string s) {

    stringstream ss(s);
    string word;
    vector<string> words;
    while (ss >> word) {            // Storing every words after space seperately
        words.push_back(word);
    }

    string ans;
    int flag=1;
    for(auto it :words){
        if(it=="double"){
            flag=2;
            continue;
        }
        else if(it=="triple"){
            flag=3;
            continue;
        }
        else if(it=="zero"){
            while(flag--){
                ans+="0";
            }
            flag=1;
        }
        else if(it=="one"){
            while(flag--){
                ans+="1";
            }
            flag=1;
        }else if(it=="two"){
            while(flag--){
                ans+="2";
            }
            flag=1;
        }else if(it=="three"){
            while(flag--){
                ans+="3";
            }
            flag=1;
        }else if(it=="four"){
            while(flag--){
                ans+="4";
            }
            flag=1;
        }else if(it=="five"){
            while(flag--){
                ans+="5";
            }
            flag=1;
        }else if(it=="six"){
            while(flag--){
                ans+="6";
            }
            flag=1;
        }else if(it=="seven"){
            while(flag--){
                ans+="7";
            }
            flag=1;
        }else if(it=="eight"){
            while(flag--){
                ans+="8";
            }
            flag=1;
        }else if(it=="nine"){
            while(flag--){
                ans+="9";
            }
            flag=1;
        }
    }
    return ans;
}

int main(){
    string s="six two double zero two zero seven one eight two three";
    cout<<getPhoneNumber(s);
    return 0;
}