#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
  bool isValid(string s) {
    if (s.length() == 0) {
      return true;
    }
    stack<char> stk;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
        stk.push(s[i]);
      } else if (s[i] == ')') {
        if (stk.empty()) {
          return false;
        }
        if (stk.top() == '(') {
          stk.pop();
        } else {
          return false;
        }
      } else if (s[i] == '}') {
        if (stk.empty()) {
          return false;
        }
        if (stk.top() == '{') {
          stk.pop();
        } else {
          return false;
        }
      } else if (s[i] == ']') {
        if (stk.empty()) {
          return false;
        }
        if (stk.top() == '[') {
          stk.pop();
        } else {
          return false;
        }
      }
    }

    if (stk.empty()) {
      return true;
    } else {
      return false;
    }
  }
};

int main() {
  string str = "({)}[]";
  Solution s;
  cout << str << " valid?: " << s.isValid(str) << endl;
  return 0;
}