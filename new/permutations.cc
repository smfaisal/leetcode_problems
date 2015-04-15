#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void dfs(vector<int>& num, int ind, vector<vector<int> >& res) {
    if (ind >= num.size()) {
      res.push_back(num);
      return;
    }
    int tmp;
    for (int i = ind; i < num.size(); i++) {
      swap(num[ind], num[i]);
      dfs(num, ind+1, res);
      swap(num[ind], num[i]);
    }
  }
  vector<vector<int> > permute(vector<int> &num) {
    vector<vector<int> > res;
    if (num.size() == 0) {
      return res;
    } else if (num.size() == 1) {
      res.push_back(num);
      return res;
    }

    dfs(num, 0, res);
    return res;
  }
};

int main() {
  Solution s;
  int a[] = {1, 2, 3, 4};
  vector<int> num(a, a+4);
  vector<vector<int> > result = s.permute(num);
  for (int i = 0; i < result.size(); i++) {
    for (int j = 0; j < result[i].size(); j++) {
      cout << result[i][j] << ", ";
    }
    cout << endl;
  }
  return 0;
}