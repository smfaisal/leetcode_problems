#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution{
public:
  void dfs(string s, int st, string r, vector<string>& res, vector<vector<bool> >& mp) {
    if (st >= s.size()) {
      res.push_back(r);
      return;
    }
    string tmp;
    for (int i = st; i < s.size(); i++) {
      if (mp[st][i]) {
        tmp = s.substr(st, i-st+1);
        if (i != s.size()-1) {
          dfs(s, i+1, r+tmp+" ", res, mp);
        } else {
          dfs(s, i+1, r+tmp, res, mp);
        }
      }
    }
  }
  vector<string> wordBreak(string s, unordered_set<string>& dict) {
    vector<string> res;
    if (s.size() == 0) {
      return res;
    }
    vector<vector<bool> > mp(s.size(), vector<bool>(s.size(), false));

    string substr;
    for (int i = 0; i < s.size(); i++) {
      for (int j = i; j < s.size(); j++) {
        substr = s.substr(i, j-i+1);
        if (dict.find(substr) != dict.end()) {
          mp[i][j] = true;
        }
      }
    }

    for (int i = 0; i < s.size(); i++) {
      for (int j = 0; j < s.size(); j++) {
        cout << mp[i][j] << " ";
      }
      cout << endl;
    }
    cout << endl;
    string r;
    dfs(s, 0, r, res, mp);
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