#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution{
public:
  void dfs(int n, int l, int r, string str, vector<string>& res) {
    if (r == 0) {
      res.push_back(str);
      return;
    }
    if (l > 0) {
      dfs(n, l-1, r, str+"(", res);
    }
    if (r > l) {
      dfs(n, l, r-1, str+")", res);
    }

  }
  vector<string> validParenthesis(int n) {
    vector<string> res;
    if (n == 0) {
      return res;
    }
    string r;
    dfs(n, n, n, r, res);
    return res;
  }
};

int main() {
  Solution s;
  vector<string> res = s.validParenthesis(5);
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << endl;
  }
  return 0;
}