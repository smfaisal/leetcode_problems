#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<vector<int> > fourSum(vector<int> &num, int target) {
    vector<vector<int> > result;
    if (num.size() < 4) {
      return result;
    }
    sort(num.begin(), num.end());
    for (int i = 0; i < num.size()-3 && num[i] <= 0; i++) {
      if (i > 0 && num[i-1] == num[i]) {
        continue;
      }
      for (int j = i+1; j < num.size()-2; j++) {
        if (j > i+1 && num[j-1] == num[j]) {
          continue;
        }
        if (num[i] + num[j] > target) {
          break;
        }
        for (int k = j+1; k < num.size()-1; k++) {
          if (k > j+1 && num[k-1] == num[k]) {
            continue;
          }
          if (num[i] + num[j] + num[k] > target) {
            break;
          }
          for (int l = k+1; k < num.size(); l++) {
            if (l > k+1 && num[l-1] == num[l]) {
              continue;
            }
            if (num[i] + num[j] + num[k] + num[l] == target) {
              vector<int> res;
              res.push_back(num[i]);
              res.push_back(num[j]);
              res.push_back(num[k]);
              res.push_back(num[l]);
              result.push_back(res);
            } else if (num[i] + num[j] + num[k] + num[l] > target) {
              break;
            }
          }
        }
      }
    }
    return result;
  }
};

int main() {
  Solution s;
  int arr[] = {0, 0, 0, 0}; //{-1, 0, 1, 2, -1, -4};
  vector<int> num(arr, arr+4);
  vector<vector<int> > res = s.fourSum(num, 0);
  for (int i = 0; i < res.size(); i++) {
    for (int j = 0; j < res[i].size(); j++) {
      cout << res[i][j] << ", ";
    }
    cout << endl;
  }
  return 0;
}
