#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  void gp(int l, int r, int n, string res, vector<string>& result) {
    if (l > n) {
      return;
    }
    if (l==n && r == n) {
      result.push_back(res);
    } else {
      gp(l+1, r, n, res+"(", result);
      if (r < l) {
        gp(l, r+1, n, res+")", result);
      }
    }
  }

  vector<string> generateParenthesis(int n) {
    vector<string> result;
    if (n == 0) {
      return result;
    }
    gp(0, 0, n, "", result);
    return result;
  }
};

int main() {
  Solution s;
  vector<string> result = s.generateParenthesis(3);
  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << endl;
  }
  return 0;
}