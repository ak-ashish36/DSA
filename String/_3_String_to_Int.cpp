//https://leetcode.com/problems/string-to-integer-atoi/
#include <bits/stdc++.h>
using namespace std;
int myAtoi(string str){
    bool neg = false,pos=false,found=false;
    unsigned long long val=0;

    for (int i = 0; i < str.length(); i++){
        if (str[i] == ' '){
            if(found||pos||neg)break;
            continue;
        }
        else if (str[i] == '-'){
            if(pos||neg||found){break;}
            neg = true;
        }
        else if(str[i]=='+'){
            if(neg||pos||found){break;}
            pos=true;
        }
        else if ((int)str[i] >= 48 && (int)str[i] <= 57){
            if(found){break;}
            found=true;
            val = 0;
            while (i < str.length() && isdigit(str[i])){
                if(val>INT_MAX){break;}
                val = (val * 10) + (str[i] - '0');
                i++;
            }
            i--;
        }else{
            if(!found) return 0;
            else if(found)break;
        }
    }
       
    if (val>INT_MAX && !neg){return INT_MAX;}
    else if(val!=0 && (-1*val)<=INT_MIN){return INT_MIN;}


    if (neg){
        return (int)val * -1;
    }
    return (int)val;

    if (neg){
        return val * -1;
    }
    return val;
}
int main(){
    string str="18446744073709551617";
    cout<<myAtoi(str);
    return 0;
}