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
    vector<vector<int> > gain(row, vector<int>(col, 0));

    power[0][0] = (dungeon[0][0] < 1)?(1-dungeon[0][0]):0;
    gain[0][0] = (dungeon[0][0] > 0)?dungeon[0][0]:0;

    for (int i = 1; i < row; i++) {
      power[i][0] = power[i-1][0];
      if (dungeon[i][0] < 0) {
        if (gain[i-1][0] + dungeon[i][0] < 0) {
          power[i][0]-= (gain[i-1][0]+dungeon[i][0]);
          gain[i][0] = 0;
        } else {
          gain[i][0] = gain[i-1][0]+dungeon[i][0];
        }

      } else {
        gain[i][0] = dungeon[i][0]+gain[i-1][0];
      }
      if (power[i][0]+gain[i-1][0]+dungeon[i][0] == 0) {
        power[i][0]++;
      }
    }
    for (int i = 1; i < col; i++) {
      power[0][i] = power[0][i-1];
      if (dungeon[0][i] < 0) {
        if (gain[0][i-1] + dungeon[0][i] < 0) {
          power[0][i]-= (gain[0][i-1]+dungeon[0][i]);
          gain[0][i] = 0;
        } else {
          gain[0][i] = gain[0][i-1]+dungeon[0][i];
        }

      } else {
        gain[0][i] = dungeon[0][i]+gain[0][i-1];
      }
      if (power[0][i]+gain[0][i-1]+dungeon[0][i] == 0) {
        power[0][i]++;
      }
    }
    int tmp;
    for (int i = 1; i < row; i++) {
      for (int j = 1; j < col; j++) {
        power[i][j] = min(power[i-1][j], power[i][j-1]);

        if (power[i-1][j] < power[i][j-1]) {
          tmp = gain[i-1][j];
        } else {
          tmp = gain[i][j-1];
        }
        if (dungeon[i][j] < 0) {
          if (tmp+dungeon[i][j] < 0) {
            power[i][j] -= (tmp+dungeon[i][j]);
          }
          if (power[i][j]+tmp+dungeon[i][j] == 0) {
            power[i][j]++;
          }
        }

//        tmp = max(gain[i-1][j], gain[i][j-1]);
        gain[i][j] = dungeon[i][j]+tmp;
      }
    }

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        cout << power[i][j] << " ";
      }
      cout << endl;
    }
    return (power[row-1][col-1]>0)?power[row-1][col-1]:1;
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
