#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
    int paths = 0;
    int i = 0;
    int j = 0;
    if (obstacleGrid.size() == 0) {
      return paths;
    }
    int row = obstacleGrid.size();
    int col = obstacleGrid[0].size();
    vector<vector<int> > p(row, vector<int>(col, 0));
    while (i < obstacleGrid[0].size() &&
           obstacleGrid[0][i] != 1) {
      p[0][i++] = 1;
    }
    if (i < obstacleGrid[0].size()) {
      while (i < obstacleGrid[0].size()) {
        p[0][i++] = 0;
      }
    }
    i = 0;
    while (i < obstacleGrid.size() &&
           obstacleGrid[i][0] != 1) {
      p[i++][0] = 1;
    }
    if (i < obstacleGrid.size()) {
      while (i < obstacleGrid.size()) {
        p[i++][0] = 0;
      }
    }

    for (i = 1; i < obstacleGrid.size(); i++) {
      for (j = 1; j < obstacleGrid[0].size(); j++) {
        if (obstacleGrid[i][j] == 1) {
          p[i][j] = 0;
        } else {
          p[i][j] = p[i][j-1] + p[i-1][j];
        }
      }
    }
    return p[row-1][col-1];
  }
};

int main() {
  Solution s;


  return 0;
}
