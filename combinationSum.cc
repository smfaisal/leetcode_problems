#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void sum(vector<int>& candidates, int index, int target, vector<int>& cur, vector<vector<int> >& result){
    if (target == 0) {
      result.push_back(cur);
      return;
    } else if (target < 0) {
      return;
    } else {
      while (index < candidates.size() && target-candidates[index] >= 0) {
        cur.push_back(candidates[index]);
        sum(candidates, index, target-candidates[index], cur, result);
        index++;
        cur.pop_back();
      }
    }
  }

  vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
    vector<int> cur;
    vector<vector<int> > result;
    if (candidates.size() == 0) {
      return result;
    }
    sort(candidates.begin(), candidates.end());
    sum(candidates, 0, target, cur, result);
    return result;
  }
};

int main() {
  Solution s;
  int a[] = {2, 3, 6, 7};
  vector<int> candidates(a, a+4);
  vector<vector<int> > res = s.combinationSum(candidates, 11);
  cout << "Result size: " << res.size() << endl;
  for (int i = 0; i < res.size(); i++) {
    for (int j = 0; j < res[i].size(); j++) {
      cout << res[i][j] << ", ";
    }
    cout << endl;
  }
  return 0;
}