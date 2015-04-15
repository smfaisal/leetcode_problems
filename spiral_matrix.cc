#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int> > &matrix) {
    vector<int> result;
    if (matrix.size() == 0) {
      return result;
    }
    int row_st = 0;
    int col_st = 0;
    int row_end = matrix.size();
    int col_end = matrix[0].size();
    int x = 0;
    int y = 0;
    bool row = true;
    bool row_forward = true;
    bool col_forward = true;
    int i = 0;
    while(i < matrix.size()*matrix[0].size()) {
      if (row) {
        if (row_forward) {
          y = col_st;
          while (y < col_end) {
            result.push_back(matrix[x][y++]);
            i++;
          }
          row_st++;
          y--;
          row_forward = false;
        } else {
          y = col_end-1;
          while (y >= col_st) {
            result.push_back(matrix[x][y--]);
            i++;
          }
          y++;
          row_forward = true;
        }
        // Control row/col st/end
        row = false;
      } else {
        if (col_forward) {
          x = row_st;
          while (x < row_end) {
            result.push_back(matrix[x++][y]);
            i++;
          }
          col_end--;
          x--;
          col_forward = false;
        } else {
          row_end--;
          x = row_end-1;
          while (x >= row_st) {
            result.push_back(matrix[x--][y]);
            i++;
          }
          x++;
          col_st++;
          col_forward = true;
        }
        // Control row/col st/end
        row = true;
      }
    }
    return result;
  }
};

int main() {
  Solution s;
  int a1[] = {1, 2, 3, 4};
//  int a2[] = {5, 6, 7, 8};
//  int a3[] = {9, 10, 11, 12};
//  int a4[] = {13, 14, 15, 16};
  vector<int> v1(a1, a1+4);
//  vector<int> v2(a2, a1+4);
//  vector<int> v3(a3, a1+4);
//  vector<int> v4(a4, a1+4);

  vector<vector<int> > matrix;
  matrix.push_back(v1);
//  matrix.push_back(v2);
//  matrix.push_back(v3);
//  matrix.push_back(v4);

  vector<int> res = s.spiralOrder(matrix);

  cout << "Spiral: " << endl;
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << ", ";
  }
  cout << endl;
  return 0;
}

