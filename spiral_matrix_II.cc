#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int> > generateMatrix(int n) {
    vector<vector<int> > result(n, vector<int>(n, 0));
    if (n == 0) {
      return result;
    }
    int row_st = 0;
    int row_end = n-1;
    int col_st = 0;
    int col_end = n-1;

    int row = true;
    int front = true;

    int i = 1;
    int row_ind = row_st;
    int col_ind = col_st;

    while (i <= n*n) {
      if (row) {
        if (front) {
          row_ind = row_st;
          for (col_ind = col_st; col_ind <= col_end; col_ind++) {
            result[row_ind][col_ind] = i++;
          }
          row_st++;
        } else {
          row_ind = row_end;
          for (col_ind = col_end; col_ind >= col_st; col_ind--) {
            result[row_ind][col_ind] = i++;
          }
          row_end--;
        }
        row = false;
      } else {
        if (front) {
          col_ind = col_end;
          for (row_ind = row_st; row_ind <= row_end; row_ind++) {
            result[row_ind][col_ind] = i++;
          }
          col_end--;
          front = false;
        } else {
          col_ind = col_st;
          for (row_ind = row_end; row_ind >= row_st; row_ind--) {
            result[row_ind][col_ind] = i++;
          }
          col_st++;
          front = true;
        }
        row = true;
      }
    }
    return result;
  }
};

int main() {
  Solution s;
  vector<vector<int> > result = s.generateMatrix(5);

  for (int i = 0; i < result.size(); i++) {
    for (int j = 0; j < result[0].size(); j++) {
      cout << result[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}