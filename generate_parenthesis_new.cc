#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  void dfs(string str, vector<string>& res, int l, int r) {
    if (l==0 && r==0) {
      res.push_back(str);
    } else {
      if (l > 0) {
        dfs(str+'(', res, l-1, r);
      }
      if (r > l) {
        dfs(str+')', res, l, r-1);
      }
    }
  }

  vector<string> generateParenthesis(int n) {
    vector<string> res;
    if (n == 0) {
      return res;
    }

    string r = "";
    dfs("", res, n, n);
    return res;
  }
};

int main() {
  Solution s;

  vector<string> res = s.generateParenthesis(3);

  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << endl;
  }
  return 0;
}