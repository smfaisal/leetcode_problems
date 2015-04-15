#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
  void solve(vector<vector<char> > &board) {
    if (board.empty()) {
      return;
    }

  	vector<vector<bool> >ns(board.size(), vector<bool>(board[0].size()));
    queue<pair<int, int> > bfs_q;

    for (int j = 0; j < board[0].size(); j++) {
      if (board[0][j] == 'O') {
        ns[0][j] = true;
        bfs_q.push(make_pair(0, j));
      }
      if (board[board.size()-1][j] == 'O') {
        //cout << "board(" << board.size()-1 << j << ") false\n";
        ns[board.size()-1][j] = true;
        bfs_q.push(make_pair(board.size()-1, j));
      }
    }
    for (int i = 0; i < board.size(); i++) {
      if (board[i][0] == 'O') {
        ns[i][0] = true;
        bfs_q.push(make_pair(i, 0));
      }
      if (board[i][board[0].size()-1] == 'O') {
        ns[i][board[0].size()-1] = true;
        bfs_q.push(make_pair(i, board[0].size()-1));
      }
    }
    int i, j;
    while (bfs_q.size() > 0) {
      i = bfs_q.front().first;
      j = bfs_q.front().second;
      bfs_q.pop();
      if (i-1 >= 0 && board[i-1][j] == 'O' && ns[i-1][j] == false) {
        ns[i-1][j] = true;
        bfs_q.push(make_pair(i-1, j));
      }
      if (i+1 < board.size() && board[i+1][j] == 'O' && ns[i+1][j] == false) {
        ns[i+1][j] = true;
        bfs_q.push(make_pair(i+1, j));
      }
      if (j-1 >= 0 && board[i][j-1] == 'O' && ns[i][j-1] == false) {
        ns[i][j-1] = true;
        bfs_q.push(make_pair(i, j-1));
      }
      if (j+1 < board[0].size() && board[i][j+1] == 'O' && ns[i][j+1] == false) {
        ns[i][j+1] = true;
        bfs_q.push(make_pair(i, j+1));
      }
    }
////		cout << "Done" << endl;
    for (int i = 1; i < board.size()-1; i++) {
      for (int j = 1; j < board[0].size()-1; j++) {
        if (ns[i][j] == false) {
          board[i][j] = 'X';
        }
      }
    }
  }
};

int main() {
  Solution s;
  char b1[] = {'O', 'X', 'X', 'O', 'X'};
  char b2[] = {'X', 'O', 'O', 'X', 'O'};
  char b3[] = {'X', 'O', 'X', 'O', 'X'};
  char b4[] = {'O', 'X', 'O', 'O', 'O'};
  char b5[] = {'X', 'X', 'O', 'X', 'O'};

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

  s.solve(board);

  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board.size(); j++) {
      cout << board[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
