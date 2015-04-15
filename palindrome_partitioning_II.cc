#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int minCut(string s) {
    if (s.size() == 0) {
      return 0;
    }
    vector<vector<bool> > palin(s.size(), vector<bool>(s.size(), false));

    for (int i = s.size()-1; i >= 0; i--) {
      for (int j = i; j < s.size(); j++) {
        if (s[i] == s[j] && (j-i < 2 || palin[i+1][j-1])) {
          palin[i][j] = true;
        }
      }
    }

    vector<int> res(s.size(), INT_MAX);
    res[0] = 0;
    for (int i = 1; i < s.size(); i++) {
      int m = INT_MAX;
      if (palin[0][i]) {
        res[i] = 0;
      } else {
        for (int k = 0; k <= i; k++) {
          if (k+1 < s.size() && palin[k+1][i]) {
            m = min(m, res[k] + 1);
          }
        }
        res[i] = m;
      }
    }
    return res[s.size()-1];
  }
};

int main() {
  Solution s;
//  cout << "abccba palindrome? : " << s.isPalindrome("abccba") << endl;
//  vector<vector<string> > res = s.partition("cdd");
//  for (int v = 0; v < res.size(); v++) {
//    for (int s = 0; s != res[v].size(); s++) {
//      cout << res[v][s] << ", ";
//    }
//    cout << endl;
//  }
  cout << "Res: " << s.minCut("aab") << endl;

  return 0;
}