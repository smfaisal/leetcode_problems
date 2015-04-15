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
  string countAndSay(int n) {
    string res;
    if (n < 1) {
      return res;
    }
    int i = 1;
    res = "1";
    string tmp;

    for (i=2; i <= n; i++) {
      tmp = "";
      if (res.size() == 1) {
        tmp += "1";
        tmp+= res[0];
//        cout << tmp << endl;
      } else {
        int j = 1;
        int c = 1;
        while (j < res.size()) {
          if (res[j] == res[j-1]) {
            c++;
            j++;
          } else {
            tmp += numToStr(c);
            tmp += res[j-1];
            c = 1;
            j++;
          }
        }
        tmp+= numToStr(c);
        tmp+= res[j-1];

      }
      res = tmp;
//      cout << res << endl;
    }
    return res;
  }
};

int main() {
  Solution s;
  cout << "sequence: " << s.countAndSay(6) << endl;
  return 0;
}