#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void dfs(vector<vector<char> >& grid, int i, int j, vector<vector<char> >& island) {
    if (grid[i][j] == '0') {
      island[i][j] = 0;
    } else {
      island[i][j] = 1;
    }    // i-1
    if (i-1 >= 0) {
      if (grid[i-1][j] == '0') {
        island[i-1][j] = 0;
      } else if (island[i-1][j] == -1) {
        dfs(grid, i-1, j, island);
      }
    }
    // i+1
    if (i+1 < grid.size()) {
      if (grid[i+1][j] == '0') {
        island[i+1][j] = 0;
      } else if (island[i+1][j] == -1) {
        dfs(grid, i+1, j, island);
      }
    }
    if (j-1 >= 0) {
      if (grid[i][j-1] == '0') {
        island[i][j-1] = 0;
      } else if (island[i][j-1] == -1) {
        dfs(grid, i, j-1, island);
      }
    }
    if (j+1 < grid[0].size()) {
      if (grid[i][j+1] == '0') {
        island[i][j+1] = 0;
      } else if (island[i][j+1] == -1) {
        dfs(grid, i, j+1, island);
      }
    }

//    if ((i-1 < 0 || island[i-1][j] == 2) &&
//        (i+1 >= grid.size() || island[i+1][j] == 2) &&
//        (j-1 < 0 || island[i][j-1] == 2) &&
//        (j+1 >= grid[0].size() || island[i][j+1] == 2))
//    {
//      island[i][j] = 1;
//    } else {
//      island[i][j] = 0;
//    }
  }

  int numIslands(vector<vector<char> > &grid) {
    if (grid.size() == 0) {
      return 0;
    }

    vector<vector<char> > island(grid.size(), vector<char>(grid[0].size(), -1));
    int n = 0;
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[i].size(); j++) {
        if (grid[i][j] == '1' && island[i][j] == -1) {
          n++;
//          cout << i << ", " << j << endl;
          dfs(grid, i, j, island);
        }
      }
    }
    return n;
  }
};

int main() {
  Solution s;
  char b1[] = {'1', '1', '1', '0', '0'};
  char b2[] = {'1', '1', '1', '0', '0'};
  char b3[] = {'1', '1', '0', '1', '0'};
  char b4[] = {'0', '0', '0', '0', '0'};
  char b5[] = {'0', '0', '0', '0', '1'};

  //char b1[] = {'O', 'O', 'O', 'O'};
  //char b2[] = {'O', 'O', 'O', 'O'};
  //char b3[] = {'O', 'O', 'O', 'O'};
  //char b4[] = {'O', 'O', 'O', 'O'};

  vector<vector<char> > board;
  vector<char> r1(b1, b1+5);
  vector<char> r2(b2, b2+5);
  vector<char> r3(b3, b3+5);
  vector<char> r4(b4, b4+5);
  vector<char> r5(b5, b5+5);
  board.push_back(r1);
  board.push_back(r2);
  board.push_back(r3);
  board.push_back(r4);
  board.push_back(r5);

  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board.size(); j++) {
      cout << board[i][j] << " ";
    }
    cout << endl;
  }

  int n = s.numIslands(board);

//  for (int i = 0; i < board.size(); i++) {
//    for (int j = 0; j < board.size(); j++) {
//      cout << board[i][j] << " ";
//    }
//    cout << endl;
//  }

  cout << "Number of islands: " << n << endl;
  return 0;
}