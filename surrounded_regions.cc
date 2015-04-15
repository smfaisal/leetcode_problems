#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
	unordered_set<int> grey;
  bool isSurrounded(vector<vector<char> >& brd, int i, int j, vector<vector<bool> >& surrounded) {
    // Check four boundary points
    if (surrounded[i][j]) {
			return true;
		}
		if (brd[i][j] == 'X') {
      //cout << "brd(" << i << j << ") surrounded" << endl;
      surrounded[i][j] = true;
      return true;
    } else if (i <= 0 || i >= brd.size()-1 ||
							 j <= 0 || j >= brd[0].size()-1) {
      surrounded[i][j] = false;
			return false;
		} else {
			grey.insert(i*brd[0].size()+j);
      if ((grey.find((i-1)*brd[0].size()+j) != grey.end() || isSurrounded(brd, i-1, j, surrounded)) &&
          (grey.find((i+1)*brd[0].size()+j) != grey.end() || isSurrounded(brd, i+1, j, surrounded)) &&
          (grey.find(i*brd[0].size()+j-1) != grey.end() || isSurrounded(brd, i, j-1, surrounded)) &&
          (grey.find(i*brd[0].size()+j+1) != grey.end() || isSurrounded(brd, i, j+1, surrounded))) {
        //cout << "brd(" << i << j << ") surrounded!" << endl;
        grey.erase(i*brd[0].size()+j);
				surrounded[i][j] = true;
        brd[i][j] = 'X';
				return true;
      } else {
        surrounded[i][j] = false;
        return false;
      }
    }
  }

  void solve(vector<vector<char> > &board) {
    if (board.empty()) {
      return;
    }

  	vector<vector<bool> >surrounded(board.size(), vector<bool>(board[0].size(), false));
    for (int j = 0; j < board[0].size(); j++) {
      if (board[0][j] == 'O') {
        surrounded[0][j] = false;
      }
      if (board[board.size()-1][j] == 'O') {
        //cout << "board(" << board.size()-1 << j << ") false\n";
        surrounded[board.size()-1][j] = false;
      }
    }
    for (int i = 0; i < board.size(); i++) {
      if (board[i][0] == 'O') {
        surrounded[i][0] = false;
      }
      if (board[i][board[0].size()-1] == 'O') {
        surrounded[i][board[0].size()-1] = false;
      }
    }
//		cout << "Done" << endl;
    for (int i = 1; i < board.size()-1; i++) {
      for (int j = 1; j < board[0].size()-1; j++) {
        if (board[i][j] == 'O') {
          if (isSurrounded(board, i, j, surrounded)) {
            board[i][j] = 'X';
          }
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
