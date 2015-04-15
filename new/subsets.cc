#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void dfs(vector<int>& s, int st, vector<int>& r, vector<vector<int> >& res) {
    if (st >= s.size()) {
      res.push_back(r);
      return;
    }
//    for (int i = st; i < s.size(); i++) {
      dfs(s, st+1, r, res);
      r.push_back(s[st]);
      dfs(s, st+1, r, res);
      r.pop_back();
//    }
  }
  vector<vector<int> > subsets(vector<int> &S) {
    vector<vector<int> > res;
    if (S.size() < 1) {
      return res;
    }

    sort(S.begin(), S.end());
    vector<int> r;
    dfs(S, 0, r, res);
    return res;
  }
};

int main() {
  Solution s;
  vector<int> vec;
  vec.push_back(1);
  vec.push_back(1);
  vec.push_back(3);

  vector<vector<int> > result = s.subsets(vec);
  for (int i = 0; i < result.size(); i++) {
    cout << "[ ";
    for (int j = 0; j < result[i].size(); j++) {
      cout << result[i][j] << ' ';
    }
    cout << "]" << endl;
  }
  return 0;
}