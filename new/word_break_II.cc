#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
  void dfs(string s, int st, int end, string r, vector<vector<bool> >& mp, vector<string>& res) {
    if (st > end) {
      res.push_back(r);
      return;
    }
    string str;
    for (int i = st; i <= end; i++) {
      if (mp[st][i]) {
        str = s.substr(st, i-st+1)+" ";
        dfs(s, i+1, end, r + str, mp, res);
      }
    }
  }
  vector<string> wordBreak(string s, unordered_set<string> &dict) {
    vector<string> res;
    if (s.size() == 0) {
      return res;
    }
    vector<vector<bool> > mp(s.size(), vector<bool>(s.size(), false));

    for (int i = 0; i < s.size(); i++) {
      for (int j = i+1; j < s.size(); j++) {
        if (dict.find(s.substr(i, j-i+1)) != dict.end()) {
          mp[i][j] = true;
        }
      }
    }
    string r;
    dfs(s, 0, s.size()-1, r, mp, res);
    return res;
  }
};

int main() {
  Solution s;
  unordered_set<string> dict;
  dict.insert("cats");
  dict.insert("and");
  dict.insert("dog");
  dict.insert("cat");
  dict.insert("sand");

  vector<string> res = s.wordBreak("catsanddog", dict);

  cout << "Word Break?: " << endl;
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << endl;
  }

  return 0;
}