#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
  int titleToNumber(string s) {
    if (s.size() == 0) {
      return 0;
    }
    int len = s.size();
    int num = 0;
    for (int i = 0; i < len; i++) {
      num += (s[i]-64)*pow(26, (len-i-1));
    }
    return num;
  }
};

int main() {
  Solution s;
  string str = "AABC";
  int res = s.titleToNumber(str);

  cout << "Number for " << str << " : " << res << endl;
  return 0;
}