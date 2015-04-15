#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
  bool dfs(vector<vector<char> >& board, int x, int y, int ind, string word, unordered_set<int>& used) {
    if (ind >= word.size()) {
      return true;
    }
    if (y+1 < board[0].size() &&
        used.find(x*board[0].size()+y+1) == used.end()) {
      if (board[x][y+1] == word[ind]) {
        used.insert(x*board[0].size()+y+1);
        if (dfs(board, x, y+1, ind+1, word, used)) {
          return true;
        }
        used.erase(x*board[0].size()+y+1);
      }
    }
    if (y-1 >= 0 &&
        used.find(x*board[0].size()+y-1) == used.end()) {
      if (board[x][y-1] == word[ind]) {
        used.insert(x*board[0].size()+y-1);
        if (dfs(board, x, y-1, ind+1, word, used)) {
          return true;
        }
        used.erase(x*board[0].size()+y-1);
      }
    }

    if (x+1 < board.size() &&
        used.find((x+1)*board[0].size()+y) == used.end()) {
      if (board[x+1][y] == word[ind]) {
        used.insert((x+1)*board[0].size()+y);
        if (dfs(board, x+1, y, ind+1, word, used)) {
          return true;
        }
        used.erase((x+1)*board[0].size()+y);
      }
    }
    if (x-1 >= 0 &&
        used.find((x-1)*board[0].size()+y) == used.end()) {
      if (board[x-1][y] == word[ind]) {
        used.insert((x-1)*board[0].size()+y);
        if (dfs(board, x-1, y, ind+1, word, used)) {
          return true;
        }
        used.erase((x-1)*board[0].size()+y);
      }
    }
    return false;
  }
  bool exist(vector<vector<char> > &board, string word) {
    if (word.size() == 0) {
      return true;
    }
    if (board.size() == 0) {
      return false;
    }
    unordered_set<int> used;
    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[0].size(); j++) {
        if (board[i][j] == word[0]) {
          used.insert(i*board[0].size()+j);
          if (dfs(board, i, j, 1, word, used)) {
            return true;
          }
          used.erase(i*board[0].size()+j);
        }
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

  bool found = s.exist(board, "a");

  cout << "Found?: " << found << endl;
  return 0;
}