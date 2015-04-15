#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void combinations(int st, int end, int k, vector<int>& vec, vector<vector<int> >& result) {
    if (k == 0) {
      result.push_back(vec);
      return;
    }
    for (int i = st; i <= end-k+1; i++) {
      vec.push_back(i);
      combinations(i+1, end, k-1, vec, result);
      vec.pop_back();
    }
  }

  vector<vector<int> > combine(int n, int k) {
    vector<vector<int> > result;
    if (n < 1 || n < k) {
      return result;
    }

    vector<int> vec;
    combinations(1, n, k, vec, result);
    return result;
  }
};

int main() {
  Solution s;
  vector<vector<int> > result = s.combine(4, 3);

  for (int i = 0; i < result.size(); i++) {
    cout << "[ ";
    for (int j = 0; j < result[i].size(); j++) {
      cout << result[i][j] << ' ';
    }
    cout << "]" << endl;
  }
  return 0;
}