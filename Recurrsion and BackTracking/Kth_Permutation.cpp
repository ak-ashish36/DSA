#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    //function to generate all possible permutations of a string
    void solve(string &str,string ans, vector < string > & res) {
      if (str.length()==0) {
        res.push_back(ans);
        return;
      }
      for (int i =0; i < str.length(); i++) {
        char c=str[i];
        string rem_str=str.substr(0,i)+str.substr(i+1);
        solve(rem_str,ans+c,res);
      }
    }

  string getPermutation(int n, int k) {
    string s;
    vector < string > res;
    //create string
    for (int i = 1; i <= n; i++) {
      s.push_back(i + '0');
    }
    solve(s,"",res);
    //sort the generated permutations
    sort(res.begin(), res.end());
    //make k 0-based indexed to point to kth sequence
    auto it = res.begin() + (k - 1);
    return *it;
  }
};

string getPermutation2(int n, int k) {
      int fact = 1;
      vector < int > numbers;
      for (int i = 1; i < n; i++) {
        fact = fact * i;
        numbers.push_back(i);
      }
      numbers.push_back(n);
      string ans = "";
      k = k - 1;
      while (true) {
        ans = ans + to_string(numbers[k / fact]);
        numbers.erase(numbers.begin() + k / fact);
        if (numbers.size() == 0) {
          break;
        }

        k = k % fact;
        fact = fact / numbers.size();
      }
      return ans;
}

int main() {
  int n = 3, k = 3;
  Solution obj;
  string ans = obj.getPermutation(n, k);
  cout << "The Kth permutation sequence is " << ans << endl;
  cout<<"Better approach ans :"<<getPermutation2(n,k);

  return 0;
}