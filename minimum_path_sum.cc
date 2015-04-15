#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int minPathSum(vector<vector<int> > &grid) {
    if (grid.size() == 0) {
      return 0;
    }
    int row = grid.size();
    int col = grid[0].size();
    vector<vector<int> > pathsum(row, vector<int>(col, 0));
    pathsum[0][0] = grid[0][0];

    for (int i = 1; i < row; i++) {
      pathsum[i][0] = pathsum[i-1][0]+grid[i][0];
    }
    for (int i = 1; i < col; i++) {
      pathsum[0][i] = pathsum[0][i-1]+grid[0][i];
    }

    for (int i = 1; i < row; i++) {
      for (int j = 1; j < col; j++) {
        if (pathsum[i][j-1] < pathsum[i-1][j]) {
          pathsum[i][j] = pathsum[i][j-1] + grid[i][j];
        } else {
          pathsum[i][j] = pathsum[i-1][j] + grid[i][j];
        }
      }
    }
    return pathsum[row-1][col-1];
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
  vector<int> v4(a4, a3+4);
  vector<vector<int> > grid;
  grid.push_back(v1);
  grid.push_back(v2);
  grid.push_back(v3);
  grid.push_back(v4);

  int min = s.minPathSum(grid);

  cout << "Min path sum: " << min << endl;
  return 0;
}