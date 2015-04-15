#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  bool valid(string s) {
    if (s.size() == 0) {
      return false;
    }
    if (s[0] == '0') {
      return false;
    }
    if (s.size() == 2) {
      if (s[0] > '2' || (s[0] == '2' && s[1] > '6')) {
        return false;
      }
    }
    return true;
  }

  int numDecodings(string s) {
    if (s.size() == 0) {
      return s.size();
    }
    vector<int> res(s.size(), 0);
    if (s[0] != '0') {
      res[0] = 1;
    }
    if (s.size() == 1) {
      return res[0];
    }
    if (valid(s.substr(0,2))) {
      res[1]++;
    }
    if (s[0] != '0' && s[1] != '0' ) {
      res[1]++;
    }

    for (int i = 2; i < s.size(); i++) {
      if (s[i] != '0') {
        res[i]+= res[i-1];
      }
      if (valid(s.substr(i-1, 2))) {
        res[i] += res[i-2];
      }
    }
    return res[s.size()-1];
  }
};

int main() {
  Solution s;
  int total;
  total = s.numDecodings("121621");

  cout << "Total ways: " << total << endl;
  return 0;
}