#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    if (strs.size() == 0) {
      return "";
    }
    int i = 0;
    char ch;
    bool done = false;
    while (!done) {
      if (i < strs[0].size()) {
        ch = strs[0][i];
      } else {
        i--;
        break;
      }
      for (int j = 1; j < strs.size(); j++) {
        if (i >= strs[j].size() || strs[j][i] != ch) {
          i--;
          done = true;
          break;
        }
      }
      if (!done) {
        i++;
      }
    }
    return strs[0].substr(0, i+1);
  }
};

int main() {
  string st[] = {"abcd", "abc"};
  vector<string> strs(st, st+2);
  Solution s;
  cout << "Longest common prefix: " << s.longestCommonPrefix(strs) << endl;
  return 0;
}