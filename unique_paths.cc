#include <iostream>

using namespace std;

class Solution {
public:
  void countPaths(int st_r, int st_c, int end_r, int end_c, int& total_paths) {
    if (st_r == end_r && st_c == end_c) {
      total_paths++;
      return;
    }
    if (st_c < end_c) {
      countPaths(st_r, st_c+1, end_r, end_c, total_paths);
    }
    if (st_r < end_r) {
      countPaths(st_r+1, st_c, end_r, end_c, total_paths);
    }
  }

  int uniquePaths(int m, int n) {
    int total_paths = 0;

    if (m == 0 || n == 0) {
      return total_paths;
    }
    countPaths(0, 0, m-1, n-1, total_paths);
    return total_paths;
  }
};

int main() {
  Solution s;
  int total = s.uniquePaths(23, 12);
  cout << "Total paths: " << total << endl;
  return 0;
}