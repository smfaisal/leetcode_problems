#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<vector<int> > threeSum(vector<int> &num) {
    vector<vector<int> > res;

    if (num.size() == 0) {
      return res;
    }
    sort(num.begin(), num.end());
    int k;
    for (int i = 0; i < num.size()-2 && num[i] <= 0; i++) {
      if (i && num[i] == num[i-1]) {
        continue;
      }
      for (int j = i+1; j < num.size()-1 && num[i]+num[j] <= 0; j++) {
        if (j > i+1 && num[j] == num[j-1]) {
          continue;
        }
        k = num.size()-1;

        while (k > j && num[i]+num[j]+num[k] > 0) {
          k--;
        }
        if (k > j && num[i]+num[j]+num[k] == 0) {
          vector<int> r;
          r.push_back(num[i]);
          r.push_back(num[j]);
          r.push_back(num[k]);
          res.push_back(r);
        }
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  int a[] = {1,2,-2,-1};//-1, 0, 1, 2, -1, -4};
  vector<int> num(a, a+4);

  vector<vector<int> > res = s.threeSum(num);

  for (int i = 0; i < res.size(); i++) {
    for (int j = 0; j < res[i].size(); j++) {
      cout << res[i][j] << ", ";
    }
    cout << endl;
  }

  return 0;
}