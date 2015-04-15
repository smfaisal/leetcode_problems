#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  static bool myfunc(int i, int j) {
    return (i > j);
  }
  void combinations(int st, vector<int>& S, vector<vector<int> >& result) {
    if (st == S.size()) {
      result.push_back(vector<int>());
      return;
    }
    combinations(st+1, S, result);
    for (int i = result.size()-1; i >= 0; i--) {
      vector<int> r = result[i];
      r.push_back(S[st]);
      result.push_back(r);
    }
  }

  vector<vector<int> > subsets(vector<int> &S) {
    vector<vector<int> > result;
    if (S.size() == 0) {
      return result;
    }
    std::sort(S.begin(), S.end(), myfunc);

    combinations(0, S, result);
    return result;
  }
};

int main() {
  Solution s;
  vector<int> vec;
  vec.push_back(1);
  vec.push_back(2);
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