#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
  void dfs(string digits, string str, vector<string>& res, map<char, vector<char> >& mp) {
    if (digits.size() == 0) {
      res.push_back(str);
    } else {
      for (int i = 0; i < mp[digits[0]].size(); i++) {
        dfs(digits.substr(1), str+mp[digits[0]][i], res, mp);
      }
    }
  }

  vector<string> letterCombinations(string digits) {
    vector<string> res;
    if (digits.size() == 0) {
      res.push_back("");
      return res;
    }
    map<char, vector<char> > mp;
    vector<char> vec;
    char dig = '2';
    for (char c = 'a'; c <= 'z'; c++) {
      vec.push_back(c);
      if (c == 'c' || c == 'f' || c == 'i' || c == 'l' || c == 'o' || c == 's'
          || c == 'v' || c == 'z') {
        mp[dig] = vec;
        vec.clear();
        dig++;
      }
    }
    dfs(digits, "", res, mp);
    return res;
  }
};

int main() {
  Solution s;
  vector<string> res = s.letterCombinations("2");
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << endl;
  }
  return 0;
}