#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void rotate(vector<vector<int> > &matrix) {
    if (matrix.size() < 2) {
      return;
    }
    int N = matrix.size();
    for (int i = 0; i < N/2; i++) {
      int K = N-1-i;
      int tmp;
      for (int j = 0; j < K-i; j++) {
        tmp = matrix[i][i+j];
        matrix[i][i+j] = matrix[K-j][i];
        matrix[K-j][i] = matrix[K][K-j];
        matrix[K][K-j] = matrix[i+j][K];
        matrix[i+j][K] = tmp;
      }
    }
  }
};

int main() {
  Solution s;
  int a1[] = {1,2,3,4};
  int a2[] = {5,6,7,8};
  int a3[] = {9,10,11,12};
  int a4[] = {13,14,15,16};

  vector<int> v1(a1, a1+4);
  vector<int> v2(a2, a2+4);
  vector<int> v3(a3, a3+4);
  vector<int> v4(a4, a4+4);
  vector<vector<int> > matrix;
  matrix.push_back(v1);
  matrix.push_back(v2);
  matrix.push_back(v3);
  matrix.push_back(v4);

  s.rotate(matrix);
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[0].size(); j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}