#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
  string numToStr(int n) {
    stringstream ss;
    ss << n;
    return ss.str();
  }

  string read(string cur) {
    string res = "";
    int count = 1;
    char digit = cur[0];
    for (int i = 1; i < cur.size(); i++) {
      if (cur[i] == digit) {
        count++;
      } else {
        res += numToStr(count) + digit;
        digit = cur[i];
        count = 1;
      }
    }
    res += numToStr(count) + digit;

    return res;
  }

  string countAndSay(int n) {
    string res = "1";
    if (n == 0) {
      return "";
    } else if (n == 1) {
      return res;
    } else {
      while (n > 1) {
        string cur = res;
        res = read(cur);
        n--;
      }
      return res;
    }
  }
};

int main() {
  Solution s;
  cout << "sequence: " << s.countAndSay(6) << endl;
  return 0;
}