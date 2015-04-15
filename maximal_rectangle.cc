#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int maximalRectangle(vector<vector<char> > &matrix) {
    if (matrix.size() == 0) {
      return 0;
    }

    vector<vector<int> > r_len(matrix.size(), vector<int>(matrix[0].size(), 0));

    int row = matrix.size();
    int col = matrix[0].size();

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        if (j==0) {
          r_len[i][j] = matrix[i][j]-48;
        } else {
          if (matrix[i][j] == '1') {
            r_len[i][j] = r_len[i][j-1]+1;
          } else {
            r_len[i][j] = 0;
          }
        }
      }
    }

    cout << "r_len: " << endl;
    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < matrix[0].size(); j++) {
        cout << r_len[i][j] << " ";
      }
      cout << endl;
    }

    int max_area = 0;
    int b; // base of the rectangle
    int h; // height of rectangle
    int area;
    int k;
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        if (r_len[i][j] > 0) {
          b = r_len[i][j];
          h = 1;
          for (k = i-1; k >= 0; k--) {
            if (r_len[k][j] > 0) {
              area = b*h;
              if (area > max_area) {
                max_area = area;
              }
              h++;
              b = min(b, r_len[k][j]);
            } else {
//              cout << "i,j: " << i << j << " b,h: " << b << "," << h << endl;
              area = b*h;
              if (area > max_area) {
                max_area = area;
              }
              b = 0;
              h = 0;
            }
          }
          if (k < 0) {
//            cout << " b,h: " << b << "," << h << endl;
            area = b*h;
            if (area > max_area) {
              max_area = area;
            }
          }
        }
      }
    }
    return max_area;
  }
};

int main() {
  Solution s;

  char a[] = {'0','1','1','0','1','1','1','0','1','0','0','1','1','1','0','1','1','1','1','0','1','1','1','1','1','0','0','0','0','0'};

  vector<char> v1(a, a+5);
  vector<char> v2(a+5, a+10);
  vector<char> v3(a+10, a+15);
  vector<char> v4(a+15, a+20);
  vector<char> v5(a+20, a+25);
  vector<char> v6(a+25, a+30);


  vector<vector<char> >matrix;
  matrix.push_back(v1);
  matrix.push_back(v2);
  matrix.push_back(v3);
  matrix.push_back(v4);
  matrix.push_back(v5);
  matrix.push_back(v6);

  cout << "Matrix: " << endl;
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[0].size(); j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
  int area = s.maximalRectangle(matrix);

  cout << "Max rectangle: " << area << endl;
  return 0;
}