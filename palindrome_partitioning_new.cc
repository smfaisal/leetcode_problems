#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool isPalindrome(string str) {
    int i = 0;
    int j = str.size()-1;
    while (i < j) {
      if (str[i++] != str[j--]) {
        return false;
      }
    }
    return true;
  }

  void dfs(string s, int st, vector<string>& rvec, vector<vector<string> >& result, vector<vector<bool> >& palin) {
    if (st >= s.size()) {
      result.push_back(rvec);
      return;
    }
    for (int i = st; i < s.size(); i++) {
      if (palin[st][i]) {
        rvec.push_back(s.substr(st, i-st+1));
        dfs(s, i+1, rvec, result, palin);
        rvec.pop_back();
      }
    }
  }

  vector<vector<string> > partition(string s) {
    vector<vector<string> > result;
    if (s.size() == 0) {
      return result;
    }
    vector<vector<bool> > palin(s.size(), vector<bool>(s.size(), false));

    for (int i = 0; i < s.size(); i++) {
      palin[i][i] = true;
      if (s[i] == s[i+1]) {
        palin[i][i+1] = true;
      }`
    }
    for (int l = 3; l <= s.size(); l++) {
      for (int i = 0; i <= s.size()-l; i++) {
        if (s[i] == s[i+l-1]) {
          palin[i][i+l-1] = palin[i+1][i+l-2];
        }
      }
    }
//
//    for (int i = 0; i < palin.size(); i++) {
//      for (int j = 0; j < palin[i].size(); j++) {
//        cout << palin[i][j] << " ";
//      }
//      cout << endl;
//    }
    vector<string> rvec;

    for (int i = 0; i < s.size(); i++) {
      if (palin[0][i]) {
        rvec.push_back(s.substr(0, i+1));
        dfs(s, i+1, rvec, result, palin);
        rvec.pop_back();
      }
    }

    return result;
  }
};

int main() {
  Solution s;
  cout << "abccba palindrome? : " << s.isPalindrome("abccba") << endl;
  vector<vector<string> > res = s.partition("cdd");
  for (int v = 0; v < res.size(); v++) {
    for (int s = 0; s != res[v].size(); s++) {
      cout << res[v][s] << ", ";
    }
    cout << endl;
  }
  return 0;
}