#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool isValid(vector<int>& cols, int level) {
    for (int i = 0; i < level; i++) {
      if (cols[i] == cols[level] ||
          abs(cols[level]-cols[i]) == level-i) {
        return false;
      }
    }
    return true;
  }
  void nqueens(vector<int>& cols, int level, int n, vector<vector<string> >& result) {
    if (level >= n) {
      vector<string> res;
      string s = "";
      int i;
      int j;
      for (i = 0; i < n; i++) {
        s = "";
        for (j = 0; j < cols[i]; j++) {
          s += ".";
        }
        s += "Q";
        for (j = cols[i]+1; j < n; j++) {
          s+= ".";
        }
        res.push_back(s);
      }
      result.push_back(res);
    } else {
      for (int i = 0; i < n; i++) {
        cols[level] = i;
        if (isValid(cols, level)) {
          nqueens(cols, level+1, n, result);
        }
      }
    }
  }
  vector<vector<string> > solveNQueens(int n) {
    vector<vector<string> > result;
    if (n == 0) {
      return result;
    }
    vector<int> cols(n, -1);
    nqueens(cols, 0, n, result);
    return result;
  }
};

int main() {
  Solution s;
  vector<vector<string> > result = s.solveNQueens(8);
  cout << "Nqueens: " << endl;
  for (int i = 0; i < result.size(); i++) {
    for (int j = 0; j < result[i].size(); j++) {
      cout << result[i][j] << endl;
    }
    cout << endl;
  }
  return 0;
}