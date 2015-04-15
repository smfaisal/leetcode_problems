#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

  void get_perm(vector<int>& num, int s_ind, int l_ind, vector<vector<int> >&result) {
    if (s_ind == l_ind) {
      result.push_back(num);
    } else {
      for (int i = s_ind; i <= l_ind; i++) {
        int tmp = num[s_ind];
        num[s_ind] = num[i];
        num[i] = tmp;

        get_perm(num, s_ind+1, l_ind, result);

        tmp = num[s_ind];
        num[s_ind] = num[i];
        num[i] = tmp;
      }
    }
  }

  vector<vector<int> > permute(vector<int> &num) {
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