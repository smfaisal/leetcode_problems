#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int numTrees(int n) {
    if (n == 0) {
      return 0;
    }
    vector<int> num_bsts(n+1, 0);
    num_bsts[0] = 1;
    num_bsts[1] = 1;
    num_bsts[2] = 2;

    for (int i = 3; i <= n; i++) {
      int total = 0;
      for (int j = 0; j < i; j++) {
        total += num_bsts[j] * num_bsts[i-1-j];
      }
      num_bsts[i] = total;
    }
    return num_bsts[n];
  }
};

int main() {
  Solution s;
  int total = s.numTrees(4);
  cout << "Res: " << total << endl;
  return 0;
}