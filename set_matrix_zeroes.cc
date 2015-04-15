#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
  void setZeroes(vector<vector<int> > &matrix) {
    if (matrix.size() == 0) {
      return;
    }
    int nrow = matrix.size();
    int ncol = matrix[0].size();

    unordered_set<int> row_set;
    unordered_set<int> col_set;

    for (int i = 0; i < nrow; i++) {
        for (int j = 0; j < ncol; j++) {
            if (matrix[i][j] == 0) {
              row_set.insert(i);
              col_set.insert(j);
            }
        }
    }
    unordered_set<int>::iterator it;

    for (it = row_set.begin(); it != row_set.end(); it++) {
      for (int i = 0; i < ncol; i++) {
        matrix[*it][i] = 0;
      }
    }
    for (it = col_set.begin(); it != col_set.end(); it++) {
      for (int i = 0; i < nrow; i++) {
        matrix[i][*it] = 0;
      }
    }
  }
};

int main() {
  Solution s;
  int a1[] = {0,0,0,5};
  int a2[] = {4,3,1,4};
  int a3[] = {0,1,1,4};
  int a4[] = {1,2,1,3};
  int a5[] = {0,0,1,1};

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

  s.setZeroes(matrix);
  cout << "After set zeroes..." << endl;
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[0].size(); j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}