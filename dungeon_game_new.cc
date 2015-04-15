#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int calculateMinimumHP(vector<vector<int> > &dungeon) {
    if (dungeon.size() == 0) {
      return 0;
    }
    int row = dungeon.size();
    int col = dungeon[0].size();

    vector<vector<int> > power(row, vector<int>(col, 0));

    power[row-1][col-1] = (dungeon[row-1][col-1] > 0)?1:-dungeon[row-1][col-1]+1;

    for (int i = row-2; i >= 0; i--) {
      power[i][col-1] = power[i+1][col-1]-dungeon[i][col-1];
      if (power[i][col-1] < 1) {
        power[i][col-1] = 1;
      }
    }

    for (int i = col-2; i >= 0; i--) {
      power[row-1][i] = power[row-1][i+1]-dungeon[row-1][i];
      if (power[row-1][i] < 1) {
        power[row-1][i] = 1;
      }
    }
    int tmp;
    for (int i = row-2; i >= 0; i--) {
      for (int j = col-2; j >= 0; j--) {
        tmp = min(power[i+1][j], power[i][j+1]);
        power[i][j] = tmp - dungeon[i][j];
        if (power[i][j] < 1) {
          power[i][j] = 1;
        }
      }
    }
    return power[0][0];
  }
};

int main() {
  Solution s;
  int b1[] = {1, -3, 3};
  int b2[] = {0, -2, 0};
  int b3[] = {-3, -3, -3};
//  int b4[] = {'O', 'X', 'O', 'O', 'O'};
//  int b5[] = {'X', 'X', 'O', 'X', 'O'};

  //char b1[] = {'O', 'O', 'O', 'O'};
  //char b2[] = {'O', 'O', 'O', 'O'};
  //char b3[] = {'O', 'O', 'O', 'O'};
  //char b4[] = {'O', 'O', 'O', 'O'};

  vector<vector<int> > board;
  vector<int> r1(b1, b1+3);
  vector<int> r2(b2, b2+3);
  vector<int> r3(b3, b3+3);
//  vector<int> r4(b4, b4+5);
//  vector<int> r5(b5, b5+5);
  board.push_back(r1);
  board.push_back(r2);
  board.push_back(r3);
//  board.push_back(r4);
//  board.push_back(r5);

  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[0].size(); j++) {
      cout << board[i][j] << " ";
    }
    cout << endl;
  }

  int mp = s.calculateMinimumHP(board);

  cout << "Min power: " << mp << endl;
  return 0;
}
