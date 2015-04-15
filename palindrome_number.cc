#include <iostream>

using namespace std;

class Solution {
public:
  bool check(int x, int& y) {
    if (x == 0) {
      return true;
    }
    if (check(x/10, y)) {
      if (x%10 == y%10) {
        y = y/10;
        return true;
      } else {
        return false;
      }
    } else {
      return false;
    }
  }

  bool isPalindrome(int x) {
    if (x < 0) {
      return false;
    } else {
      return check(x, x);
    }
  }
};

int main() {
  Solution s;
  int a = 12112321121;
  cout << a << " is palindrome?: " << s.isPalindrome(a) << endl;
  return 0;
}