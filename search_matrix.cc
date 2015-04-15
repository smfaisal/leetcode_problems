#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool searchMatrix(vector<vector<int> > &matrix, int target) {
    if (matrix.size() == 0) {
      return false;
    }

    int nrow = matrix.size();
    int ncol = matrix[0].size();
    int row = 0;
    int col = ncol-1;

    while (1) {
      while (matrix[row][col] > target) {
        col--;
        if (col < 0) {
          return false;
        }
      }
      if (matrix[row][col] == target) {
        return true;
      }

      while (matrix[row][col] < target) {
        row++;
        if (row >= nrow) {
          return false;
        }
      }
      if (matrix[row][col] == target) {
        return true;
      }
    }
  }
};

int main() {
  Solution s;
  int a1[] = {1,5,7,9};
  int a2[] = {10,13,14,17};
  int a3[] = {20,24,28,34};
  int a4[] = {44,48,52,59};
  int a5[] = {70,80,91,101};

  vector<int> v1(a1, a1+4);
  vector<int> v2(a2, a2+4);
  vector<int> v3(a3, a3+4);
  vector<int> v4(a4, a4+4);
  vector<int> v5(a5, a5+4);

  vector<vector<int> > matrix;
  matrix.push_back(v1);
  matrix.push_back(v2);
  matrix.push_back(v3);
  matrix.push_back(v4);
  matrix.push_back(v5);

  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[0].size(); j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }

  bool found = s.searchMatrix(matrix, 69);

  cout << "Found?: " << found << endl;
  return 0;
}

