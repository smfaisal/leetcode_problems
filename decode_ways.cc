#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  void dfs(string s, int ind, int& total) {
    if (ind >= s.size()) {
      total++;
      return;
    }
//    total++;
    ind++;
    dfs(s, ind, total);
    if (s[ind-1] == '1') {
      ind++;
      dfs(s, ind, total);
    } else if(s[ind-1] == '2') {
      if (s[ind] > '0' && s[ind] <= '6') {
        ind++;
        dfs(s, ind, total);
      }
    }
  }

  int numDecodings(string s) {
    if (s.size() < 2) {
      return s.size();
    }
    int total = 0;
    dfs(s, 0, total);
    return total;
  }
};

int main() {
  Solution s;
  int total;
  total = s.numDecodings("121621");

  cout << "Total ways: " << total << endl;
  return 0;
}