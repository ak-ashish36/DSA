#include <bits/stdc++.h>
using namespace std;

vector<string> getEncoding(string s){
	if (s.length()==0){
		vector<string> ans;
		ans.push_back("");
		return ans;
	}
	int code1 = s[0]-'0';   					 //Converting char into int
	char atcode1 = char('a'+code1-1);

	int code2 = stoi(s.substr(0,2));			 //Converting sring ino int
	char atcode2 = char('a'+code2-1);

	vector<string> ans;

	if(code1 != 0){
		vector<string> rec_ans=getEncoding(s.substr(1));

		for(int i=0;i<rec_ans.size();i++){
			ans.push_back(atcode1+rec_ans[i]);
		}

	}
	if(code2 >=10 && code2 <=26){
		vector<string> rec_ans=getEncoding(s.substr(2));

		for(int i=0;i<rec_ans.size();i++){
			ans.push_back(atcode2+rec_ans[i]);
		}
	}

	return ans;
}

void printEncoding(string s, string ans){
	if (s.length()==0){
		cout<<ans<<" ";
		return;
	}

	int code1 = s[0]-'0';                   //Converting char into int
	char atcode1 = char('a'+code1-1);

	int code2 = stoi(s.substr(0,2));        //Converting sring ino int
	char atcode2 = char('a'+code2-1);

	if(code1 != 0)
		printEncoding(s.substr(1),ans + atcode1);
	if(code2 >=10 && code2 <=26)
		printEncoding(s.substr(2),ans + atcode2);
}

int main(){
	string str="123";
    vector<string> ans=getEncoding(str);
    for(string i:ans){
        cout<<i<<" ";
    }
    cout<<"\nBetter Approac Sol\n";
	printEncoding("123","");
	return 0;
}