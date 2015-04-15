#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void find_start(vector<vector<char> >& board, char ch, int& st_row, int& st_col) {
    if (st_col+1 < board[st_row].size()) {
      st_col++;
    } else {
      st_row++;
      st_col = 0;
    }

    while (st_row < board.size()) {
      while (st_col < board[st_row].size()) {
        if (board[st_row][st_col] == ch) {
          return;
        }
        st_col++;
        if (st_col >= board[st_row].size()) {
          st_row++;
          st_col = 0;
          break;

        }
      }
    }
    return;
  }

  bool dfs(vector<vector<char> > &board, string word, int ind, vector<vector<bool> >& used, int st_r, int st_c) {
    if (ind == word.size()) {
      return true;
    }
    bool found = false;
    if (st_r - 1 >= 0) {
      if (!used[st_r-1][st_c] && board[st_r-1][st_c] == word[ind]) {
        used[st_r-1][st_c] = true;
        found = dfs(board, word, ind+1, used, st_r-1, st_c);
        if (found) {
          return true;
        } else {
          used[st_r-1][st_c] = false;
        }
      }
    }
    if (st_r + 1 < board.size()) {
      if (!used[st_r+1][st_c] && board[st_r+1][st_c] == word[ind]) {
        used[st_r+1][st_c] = true;
        found = dfs(board, word, ind+1, used, st_r+1, st_c);
        if (found) {
          return true;
        } else {
          used[st_r+1][st_c] = false;
        }
      }
    }
    if (st_c - 1 >= 0) {
      if (!used[st_r][st_c-1] && board[st_r][st_c-1] == word[ind]) {
        used[st_r][st_c-1] = true;
        found = dfs(board, word, ind+1, used, st_r, st_c-1);
        if (found) {
          return true;
        } else {
          used[st_r][st_c-1] = false;
        }
      }
    }
    if (st_c + 1 < board[st_r].size()) {
      if (!used[st_r][st_c+1] && board[st_r][st_c+1] == word[ind]) {
        used[st_r][st_c+1] = true;
        found = dfs(board, word, ind+1, used, st_r, st_c+1);
        if (found) {
          return true;
        } else {
          used[st_r][st_c+1] = false;
        }
      }
    }
    return found;
  }

  bool exist(vector<vector<char> > &board, string word) {
    if (board.size() == 0 || word.size() == 0) {
      return false;
    }
    int nrow = board.size();
    int ncol = board[0].size();

    int st_row = 0;
    int st_col = -1;
    bool found = false;
    while (1) {
      vector<vector<bool> > used(nrow, vector<bool>(ncol, false));
      find_start(board, word[0], st_row, st_col);
      cout << "st_row: " << st_row << " st_col: " << st_col << endl;
      if ((st_row >= 0 && st_row < nrow) &&
          (st_col >= 0 && st_col < ncol)) {
        used[st_row][st_col] = true;
        found = dfs(board, word, 1, used, st_row, st_col);
        used[st_row][st_col] = false;
        if (found) {
          return true;
        }
      } else {
        break;
      }
    }
    return false;
  }
};

int main() {
  Solution s;
  char a1[] = "FYCENRD";//{'A', 'B', 'C', 'E'};
  char a2[] = "KLNFINU";//{'S', 'F', 'E', 'S'};
  char a3[] = "AAARAHR";//{'A', 'D', 'E', 'E'};
  char a4[] = "NDKLPNE";//{'W', 'X', 'K', 'T'};
  char a5[] = "ALANSAP";//{'C', 'S', 'E', 'L'};
  char a6[] = "OOGOTPN";
  char a7[] = "HPOLANO";

  char t[] = {'a'};
  vector<char> tv(t, t+1);

  vector<char> v1(a1, a1+7);
  vector<char> v2(a2, a2+7);
  vector<char> v3(a3, a3+7);
  vector<char> v4(a4, a4+7);
  vector<char> v5(a5, a5+7);
  vector<char> v6(a6, a6+7);
  vector<char> v7(a7, a7+7);

  vector<vector<char> > board;
  board.push_back(tv);
//  board.push_back(v1);
//  board.push_back(v2);
//  board.push_back(v3);
//  board.push_back(v4);
//  board.push_back(v5);
//  board.push_back(v6);
//  board.push_back(v7);

  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[0].size(); j++) {
      cout << board[i][j] << " ";
    }
    cout << endl;
  }

  bool found = s.exist(board, "B");

  cout << "Found?: " << found << endl;
  return 0;
}
