#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<vector<int> > threeSum(vector<int> &num) {
    vector<vector<int> > result;
    if (num.size() < 3) {
      return result;
    }
    sort(num.begin(), num.end());
    for (int i = 0; i < num.size() && num[i] <= 0; i++) {
      //cout << "i: " << i << " num[i]: " << num[i] << endl;
      if (i > 0 && num[i-1] == num[i]) {
        continue;
      }
      for (int j = i+1; j < num.size(); j++) {
        //cout << "j: " << j << " num[j]: " << num[j] << endl;
        if (j > i+1 && num[j-1] == num[j]) {
          continue;
        }
        if (num[i] + num[j] > 0) {
          break;
        }
        for (int k = j+1; k < num.size(); k++) {
          //cout << "k: " << k << " num[k]: " << num[k] << endl;
          if (k > j+1 && num[k-1] == num[k]) {
            continue;
          }
          if (num[i] + num[j] + num[k] == 0) {
            vector<int> res;
            res.push_back(num[i]);
            res.push_back(num[j]);
            res.push_back(num[k]);
            result.push_back(res);
          } else if (num[i] + num[j] + num[k] > 0) {
            break;
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
  vector<int> num(arr, arr+6);
  vector<vector<int> > res = s.threeSum(num);
  for (int i = 0; i < res.size(); i++) {
    for (int j = 0; j < res[i].size(); j++) {
      cout << res[i][j] << ", ";
    }
    cout << endl;
  }
  return 0;
}
