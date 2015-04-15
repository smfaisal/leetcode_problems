#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string convert(string s, int nRows) {
    string res = "";
    if (s.length() < 2 || nRows < 2) {
      return s;
    }
    vector<string> holders(nRows, "");
    int magic = nRows * 2 - 2;

    for (int i = 0; i < s.length(); i++) {
      int mod = i % magic;
      if (mod < nRows) {
        holders[mod]+= s[i];
      } else {
        holders[magic-mod]+= s[i];
      }
    }
    for (int i = 0; i < nRows; i++) {
      res+= holders[i];
    }
    return res;
  }
};

int main() {
  string str = "paypalishiring";
  Solution s;
  cout << "Zigzag is: " << s.convert(str, 5) << endl;
  return 0;
}