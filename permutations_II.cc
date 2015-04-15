#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

  void get_perm(vector<int>& num, int s_ind, int l_ind, vector<vector<int> >&result) {
    if (s_ind == l_ind) {
      result.push_back(num);
    } else {
      int tmp;
      bool skip = false;
      for (int i = s_ind; i <= l_ind; i++) {
        for (int x = s_ind; x < i; x++) {
          if (num[x] == num[i]) {
            skip = true;
            break;
          }
        }
        if (skip) {
          skip = false;
          continue;
        }

        tmp = num[s_ind];
        num[s_ind] = num[i];
        num[i] = tmp;

        get_perm(num, s_ind+1, l_ind, result);

        tmp = num[s_ind];
        num[s_ind] = num[i];
        num[i] = tmp;
      }
    }
  }

  vector<vector<int> > permuteUnique(vector<int> &num) {
    vector<vector<int> > result;
    if (num.size() == 0) {
      return result;
    }

    get_perm(num, 0, num.size()-1, result);
    return result;
  }
};

int main() {
  Solution s;
  int a[] = {1, 1, 2};
  vector<int> num(a, a+3);
  vector<vector<int> > result = s.permuteUnique(num);
  for (int i = 0; i < result.size(); i++) {
    for (int j = 0; j < result[i].size(); j++) {
      cout << result[i][j] << ", ";
    }
    cout << endl;
  }
  return 0;
}