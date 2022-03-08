#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    vector <vector<string>> partition(string s) {

      vector < vector < string > > res;
      vector < string > path;
      func(0, s, path, res);
      return res;
    }

  void func(int index, string s, vector<string> & path, vector<vector<string>> & res) {
    if (index == s.size()) {
      res.push_back(path);
      return;
    }
    string ch="";
    for (int i = index; i < s.size(); ++i) {
        ch+=s[i];
      if (isPalindrome(ch)) {
        path.push_back(ch);
        func(i + 1, s, path, res);
        path.pop_back();
      }
    }
  }

  bool isPalindrome(string s) {
    string rev=s;
    reverse(rev.begin(),rev.end());
    if(rev==s){
    return true;
    }
    return false;
  }
};
int main() {
  string s = "aabb";
  Solution obj;
  vector < vector < string >> ans = obj.partition(s);
  int n = ans.size();
  cout << "The Palindromic partitions are :-" << endl;
  cout << " [ ";
  for (auto i: ans) {
    cout << "[ ";
    for (auto j: i) {
      cout << j << " ";
    }
    cout << "] ";
  }
  cout << "]";

  return 0;
}