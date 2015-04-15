#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  bool rowColValid(vector<vector<char> >& board) {

    vector<bool> rowBool(9, false);
    vector<bool> colBool(9, false);

    for (int i = 0; i < 9; i++) {
      std::fill(rowBool.begin(), rowBool.end(), false);
      std::fill(colBool.begin(), colBool.end(), false);

      for (int j = 0; j < 9; j++) {
        char c = board[i][j];

        if ( c != '.') {
          if (rowBool[c-'1']) {
            return false;
          } else {

            rowBool[c-'1'] = true;
          }
        }
        c = board[j][i];
        if ( c != '.') {
          if (colBool[c-'1']) {
            return false;
          } else {
            colBool[c-'1'] = true;
          }
        }
      }
    }
    return true;
  }

  bool blockValid(vector<vector<char> >& board) {
    vector<bool> blkBool(9, false);
    char c;
    for (int i = 0; i < 9; i+=3) {
      for (int j = 0; j < 9; j+= 3) {
        std::fill(blkBool.begin(), blkBool.end(), false);
        for (int k_i = i; k_i < i+3 ; k_i++) {
          for (int k_j = j; k_j < j+3 ; k_j++) {
            c = board[k_i][k_j];
            if ( c != '.') {
              if (blkBool[c-'1']) {
                return false;
              } else {
                blkBool[c-'1'] = true;
              }
            }
          }
        }
      }
    }
    return true;
  }


  bool isValidSudoku(vector<vector<char> >& board) {
    return (rowColValid(board) && blockValid(board));
  }
};

int main() {
  Solution s;

  char row1[] = "....5..1.";
  char row2[] = ".4.3.....";
  char row3[] = ".....3..1";
  char row4[] = "8......2.";
  char row5[] = "..2.7....";
  char row6[] = ".15......";
  char row7[] = ".....2...";
  char row8[] = ".2.9.....";
  char row9[] = "..4......";
  vector<char> vrow1(row1, row1 + sizeof(row1) / sizeof(char));
  vector<char> vrow2(row2, row2 + sizeof(row1) / sizeof(char));
  vector<char> vrow3(row3, row3 + sizeof(row1) / sizeof(char));
  vector<char> vrow4(row4, row4 + sizeof(row1) / sizeof(char));
  vector<char> vrow5(row5, row5 + sizeof(row1) / sizeof(char));
  vector<char> vrow6(row6, row6 + sizeof(row1) / sizeof(char));
  vector<char> vrow7(row7, row7 + sizeof(row1) / sizeof(char));
  vector<char> vrow8(row8, row8 + sizeof(row1) / sizeof(char));
  vector<char> vrow9(row9, row9 + sizeof(row1) / sizeof(char));
  vector<vector<char> > board;
  board.push_back(vrow1);
  board.push_back(vrow2);
  board.push_back(vrow3);
  board.push_back(vrow4);
  board.push_back(vrow5);
  board.push_back(vrow6);
  board.push_back(vrow7);
  board.push_back(vrow8);
  board.push_back(vrow9);

  bool result = s.isValidSudoku(board);
  cout << "Res: " << result << endl;

  return 0;
}